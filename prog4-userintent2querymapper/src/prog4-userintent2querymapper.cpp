//============================================================================
// Name        : prog4-userintent2querymapper.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>


using namespace std;
//threshold for query to match known question
const int threshold = 70;

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
								}
								if(word == "District")
								{
									cout << "District" << " ";
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
									getAddress = true;
								}
						}
						if(specificInfo == "address, Home")
						{
								if(line == "Home	Address")
								{
									cout << "Home Address: ";
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
						}
						cout << endl;
					}

				}
			}
			myfile.close();
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
		cout << "Your query was understood as: " << ToMatch << endl << endl;
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

//Method for checking for valid district at startup
bool ValidDistrict()
{
	cout << "Hello! Please enter district of interest" << endl;
	bool invalidDistrict = true;
	int num1;

	//Checking for valid input of district
	while(invalidDistrict == true)
	{
		string district;
		getline(cin,district);
		if(Match(district, "quit") || Match(district, "q"))
		{
			cout << "Goodbye!" << endl;
			return false;
		}
		num1 = 0;
		try
		{
			num1 = stoi(district);
			if(num1 == 5)
			{
				return true;
			}
			else
			{
				cout << "I'm sorry I do not have information on that district." << endl;
				cout << "Available districts are:\n5" << endl;
				cout << "Our type quit to cancel" << endl;
			}

		}
		catch (const invalid_argument& ia)
		{
			cout << "Please enter in the form of a number only." << endl;
		}
	}
	return false;
}

int main()
{
	if(ValidDistrict() == true)
	{
		bool quit = false;
		cout << "What would you like to know about your representative?" << endl;
		//Infinite loop until quit
		while(quit == false)
		{
			string input;
			getline(cin, input);

			if(Match(input, "quit") || Match(input, "q"))
			{
				cout << "Goodbye!" << endl;
				quit = true;
			}
			else
			{

				if(MatchQuery(input) == false)
				{
					cout << "I'm sorry I do not understand: " << input << endl << "Please rephrase or type quit." << endl;
				}
				else
				{
					cout << endl << "Anything else I can help you with? or type quit" << endl;
				}
			}
		}
	}
}
