//============================================================================
// Name        : prog5-sessionlogger.cpp
// Author      : Joshua Braun
//============================================================================
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;
//threshold for query to match known question
const int threshold = 70;
string out_file_name = "data/output.txt";

string GetBroadinfo(string info)
{
	//Looks for semicolon denoting a more specific info type
	int find = info.find(':');
	string Broadinfo = info;

	//If found it splits the string to get the broad info type
	if(info.find(':') != string::npos)
	{
		Broadinfo = Broadinfo.substr(0,find);
		return Broadinfo;
	}
	else
	{
		return Broadinfo;
	}
}

//Old method from previous project I use to getInfo from a data file
void GetInfo(string info)
{
	//Getting Broad info Category
	string BroadInfo = GetBroadinfo(info);

	string file_name = "data/District5output.txt";
	ifstream myfile(file_name);
	ofstream out_myfile(out_file_name, std::ios_base::app);
	string line;
	bool collectData = false;
	bool getAddress = false;
	int lineCount = 0;

	if (myfile.is_open())
	{

		while(getline(myfile, line))
		{
			//If line from the file matches the broad info category begin collecting data
			string str_to_check = line;
			string pattern = BroadInfo + "(.*)";
			regex pattern_to_check1(pattern);
			//If statement for just printing everything


			if(info == "Everything")
			{
				cout << line << endl;
				out_myfile << line + "\n";
			}
			else if(regex_match(str_to_check, pattern_to_check1))
			{
				collectData = true;
			}
			//If a white line is reached stop collecting data
			else if(line == "")
			{
				collectData = false;
			}
			else if(collectData == true)
			{
				//Start grabbing each word from the line
				stringstream lineStream(line);
				string word;

				//used to just grab the next two lines after an address line is found
				if(getAddress == true)
				{
					lineCount++;
					if(lineCount == 2)
					{
						getAddress = false;
						lineCount = 0;
					}
					while(lineStream >> word)
					{
						cout << word << " ";
						out_myfile << word + " ";
					}
				}
					//Used for arguments that are specific
					else if(info.find(':') != string::npos)
					{
						int find = info.find(':');
						string specificInfo = info.substr(find+1);
						//Printing name
						if(specificInfo == "name")
						{
							bool found = false;
							while(lineStream >> word)
							{
								if(found == true)
								{
									cout << word << " ";
									out_myfile << word + " ";
								}
								if(word == "Representative")
								{
									found = true;
								}

							}
						}
						//Printing region
						if(specificInfo == "region")
						{
							bool found = false;
							while(lineStream >> word)
							{
								if(found == true)
								{
									cout << word << " ";
									out_myfile << word + " ";
								}
								if(word == "District")
								{
									cout << "District" << " ";
									out_myfile << "District " << " ";
									found = true;
								}

							}
						}
						//Business Address
						if(specificInfo == "address, Columbia")
						{
								if(line == "Columbia	Address")
								{
									cout << "Business Address: ";
									out_myfile << "Business Address: ";
									getAddress = true;
								}
						}
						if(specificInfo == "address, Home")
						{
								if(line == "Home	Address")
								{
									cout << "Home Address: ";
									out_myfile << "Home Address: ";
									getAddress = true;
								}

						}
						if(specificInfo == "phone, home")
						{
							if(line.find("Home	Phone") != string::npos)
							{
								while(lineStream >> word)
								{
									cout << word << " ";
									out_myfile << word << " ";
								}
							}
						}
						if(specificInfo == "phone, business")
						{
							if(line.find("Business	Phone") != string::npos)
							{
								while(lineStream >> word)
								{
									cout << word << " ";
									out_myfile << word + " ";
								}
							}
						}
					}
					//Else is used to just print until a white line is reached
					else
					{

						stringstream lineStream(line);
						string word;
						while(lineStream >> word)
						{
							cout << word << " ";
							out_myfile << word << " ";
						}
						cout << endl;
						out_myfile << endl;
					}

				}
			}
			myfile.close();
			out_myfile.close();
		}
		else
		{
			cout << "Unable to open file - " << file_name << endl;
		}
}

//Method for actually matching two input strings
// returns true if strings match more than threshold
bool Match(string input, string ToMatch)
{

	stringstream lineStream(ToMatch);
	string wordMatch;
	int matchCount = 0;
	int matchLength = 0;
	//splits the known question into words
	while(lineStream >> wordMatch)
	{
		//counting the length of known question
		matchLength++;

		stringstream lineStream(input);
		string wordInput;
		//splits the question into words
		while(lineStream >> wordInput)
		{
			//comparing two words while ignoring case
			if(strcasecmp(wordInput.c_str(), wordMatch.c_str()) == 0)
			{
				matchCount++;
			}
		}
	}
	//calculating the percent match
	double percentMatch = matchCount*100/matchLength;

	if(percentMatch >= threshold)
	{
		ofstream out_myfile(out_file_name, std::ios_base::app);
		cout << "Your query was understood as: " + ToMatch + "\n";
		out_myfile << "Your query was understood as: " + ToMatch + "\n";

		out_myfile.close();
		return true;
	}
	else
	{
		return false;
	}


}

//Method for matching question to known questions
bool MatchQuery(string query)
{

	if(Match(query, "tell me about the representative") || Match(query, "tell me about the rep"))
	{
		GetInfo("Personal Information");
		return true;
	}
	else if(Match(query, "where does the rep live") || Match(query, "where does he live"))
	{
		GetInfo("Contact Information:address, Home");
		return true;
	}
	else if(Match(query, "How do I contact my rep") || Match(query, "what is the rep's contact information"))
	{
		GetInfo("Contact Information");
		return true;
	}
	else if(Match(query, "What committees is my rep on") || Match(query, "What committees is my repo on"))
	{
		GetInfo("Committee Assignments");
		return true;
	}
	else if(Match(query, "Tell me everything") || Match(query, "Tell me everything."))
	{
		GetInfo("Everything");
		return true;
	}
	else if(Match(query, "What bills did my rep sponsor") || Match(query, "What are my reps sponsored bills"))
	{
		GetInfo("Sponsored Bills in the House");
		return true;
	}
	else if(Match(query, "What is my rep's voting record") || Match(query, "What is their voting record"))
	{
		GetInfo("Voting Record");
		return true;
	}
	else if(Match(query, "Who is my rep") || Match(query, "Who is the rep") || Match(query, "What is my rep's name"))
	{
		GetInfo("Contact Information:name");
		return true;
	}
	else
	{
		//Returns false if the question is unknown
		return false;
	}

}

//Creates the file with a date and timestamp in the format mm-dd-yyyy_hr.min
string CreateChatFile()
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	string date = "";
	date = to_string(now->tm_mon + 1) + '-' + to_string(now->tm_mday) + '-' + to_string(now->tm_year + 1900);
	string time = to_string(now->tm_hour) + '.' + to_string(now->tm_min);

	string out_file = "data/"+date+"_"+time+".txt";
	stringstream nn;

	string myfilename;

	nn<<myfilename<<"data/"<<date<<"_"<<time<<".txt";
	ofstream myfile;
	myfile.open(nn.str());
	myfile << "hello";
	myfile.close();


	return "data/"+date+"_"+time+".txt";
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		bool quit = false;
		auto  start = std::chrono::steady_clock::now();
		int user_utter = 0; int system_utter = 0;
		out_file_name = CreateChatFile();


		ofstream out_myfile(out_file_name);
		if (out_myfile.is_open())
		{

		cout << "Welcome to District 5 chatbot!" << endl;
		cout << "What would you like to know about your representative?" << endl;
		out_myfile << "Welcome to District 5 chatbot!\nWhat would you like to know about your representative?\n";
		out_myfile.close();
		}
		else
		{
			cout << "Unable to open output file" << endl;
			return 0;
		}

		//Infinite loop until quit
		while(quit == false)
		{
		ofstream out_myfile(out_file_name, std::ios_base::app);
		if (out_myfile.is_open())
		{
			string input;
			getline(cin, input);
			user_utter++;
			if(Match(input, "quit") || Match(input, "q"))
			{
				cout << "Goodbye!" << endl;
				system_utter++;
				out_myfile << input + "\n";
				out_myfile << "Goodbye!\n";
				quit = true;
			}
			else
			{
				out_myfile << input + "\n";
				out_myfile.close();
				if(MatchQuery(input) == false)
				{
					ofstream out_myfile(out_file_name, std::ios_base::app);
					cout << "I'm sorry I do not understand: " << input << endl << "Please rephrase or type quit." << endl;
					system_utter++;
					out_myfile << "I'm sorry I do not understand: " + input +"\n"+ "Please rephrase or type quit.\n";
					out_myfile.close();
				}
				else
				{
					ofstream out_myfile(out_file_name, std::ios_base::app);
					cout << endl << "Anything else I can help you with? or type quit" << endl;
					system_utter++;
					out_myfile << "Anything else I can help you with? or type quit\n";
					out_myfile.close();
				}
			}


			out_myfile.close();
		}
		else
		{
			cout << "Unable to open output file" << endl;
			return 0;
		}

		}
		out_myfile.open(out_file_name, std::ios_base::app);

		auto  end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff_in_seconds = end - start;

		out_myfile << "\n#user_utterance: " + to_string(user_utter);
		out_myfile << "\n#system_utterance: " + to_string(system_utter);
		out_myfile << "\ntime duration: " + to_string(diff_in_seconds.count()) + " s";

		out_myfile.close();

		ifstream input_csv("data/chat_statistics.csv");
		ofstream csv("data/chat_statistics.csv", std::ios_base::app);
		string lastSession;
		string lastLine;
		while(getline(input_csv, lastLine));

		lastSession = lastLine.substr(0,lastLine.find(','));
		int num1 = 0;
		try
		{
			num1 = stoi(lastSession);
			num1++;
			lastSession = to_string(num1);
			csv << '\n' + lastSession + ",\t";
			csv << out_file_name +",\t" + to_string(user_utter) + ",\t" + to_string(system_utter) + ",\t" + to_string(diff_in_seconds.count()) + ",\t";
		}
		catch (const invalid_argument& ia)
		{
			csv << "1,\t"+ out_file_name + ",\t" + to_string(user_utter) + ",\t" + to_string(system_utter) + ",\t" + to_string(diff_in_seconds.count()) + ",\t";
		}
	}
	else
	{
		ifstream input_csv("data/chat_statistics.csv");
		string lastSession;
		int sessionNumber = 0;
		int user_utterances = 0;
		int system_utterances = 0;
		double total_duration = 0;
		string SNo;
		string chatfile;
		string userutter;
		string systemutter;
		string time;

		while(getline(input_csv,SNo, ','))
		{
			getline(input_csv, chatfile, ',');
			getline(input_csv, userutter, ',');
			getline(input_csv, systemutter, ',');
			getline(input_csv, time, '\n');
			try
			{
				user_utterances = user_utterances + stoi(userutter);
				system_utterances = system_utterances + stoi(systemutter);
				total_duration = total_duration + stoi(time);
				sessionNumber = stoi(SNo);

			}
			catch(const invalid_argument& ia)
			{
				//Not a problem
			}
		}
		input_csv.close();
		if(strcmp(argv[1],"summary") == 0)
		{
			cout << "There are " + to_string(sessionNumber) + " chats to date with the user asking " + to_string(user_utterances)
					<< " times and the system responding " << to_string(system_utterances) << " times.Total duration is " << to_string(total_duration)
					<< " seconds." <<endl;
		}
		else if(strcmp(argv[1],"showchat-summary") == 0)
		{
			int chatNumber = stoi(argv[2]);
			string currentSess;
			int chatCount = 0;
			ifstream input_csv2("data/chat_statistics.csv");
			while(getline(input_csv2,currentSess, ','))
			{
				getline(input_csv2, chatfile, ',');
				getline(input_csv2, userutter, ',');
				getline(input_csv2, systemutter, ',');
				getline(input_csv2, time, '\n');
				chatCount = chatCount + 1;
				if(chatCount == chatNumber+1)
				{
					cout << "Chat " << chatNumber << " has user asking " << stoi(userutter) <<" times and system responding "
					<< stoi(systemutter) << " times. Total duration is " << stod(time) << " seconds." << endl;
				}


			}
		}
		else if(strcmp(argv[1],"showchat") == 0)
		{
			bool found = false;
			int chatNumber = stoi(argv[2]);
			string currentSess;
			int chatCount = 0;
			ifstream input_csv2("data/chat_statistics.csv");
			while(getline(input_csv2,currentSess, ','))
			{
				getline(input_csv2, chatfile, ',');
				getline(input_csv2, userutter, ',');
				getline(input_csv2, systemutter, ',');
				getline(input_csv2, time, '\n');
				chatCount = chatCount + 1;
				if(chatCount == chatNumber+1)
				{
					found = true;
					input_csv2.close();
					cout << "Chat " << chatNumber << " chat is: " << endl;
					string chatSearch = chatfile.substr(1,',');
					ifstream input_chatFile(chatSearch);
					string line;
					while(getline(input_chatFile,line))
					{
						cout << line;
						cout << '\n';
					}
				}


			}
			if(found == false)
			{
				cout << "Error session not found there are only " << chatCount-1 <<" chat sessions" << endl;
			}
		}
		else
		{
			cout << "Invalid command line argument" << endl;
		}
	}

}
