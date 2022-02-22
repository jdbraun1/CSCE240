//============================================================================
// Name        : program2-processor.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


//Method for getting the broad information type
string GetBroadInfoType(string infotype)
{
	//Looks for semicolon denoting a more specific info type
	int find = infotype.find(':');
	string BroadInfoType = infotype;

	//If found it splits the string to get the broad info type
	if(infotype.find(':') != string::npos)
	{
		BroadInfoType = BroadInfoType.substr(0,find);
		return BroadInfoType;
	}
	else
	{
		return BroadInfoType;
	}
}

void getInfo(string infotype)
{
	//Getting Broad info Category
	string BroadInfo = GetBroadInfoType(infotype);

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
			if(line == BroadInfo)
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
				//Used for command line arguments that are specific
				else if(infotype.find(':') != string::npos)
				{
					int find = infotype.find(':');
					string specificInfo = infotype.substr(find+1);
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

int main(int argc, char** argv)
{

	//Getting command line argument in form of program name and information type
	if (argc >= 1)
	{
		cout << "Program name is: " << argv[1] << endl;
		if(argc >= 2)
		{
			getInfo(argv[2]);
		}
		else
		{
			cout << "No information in command line";
		}
	}
	else
	{
		cout << "No program in command line";
	}

	return 0;
}
