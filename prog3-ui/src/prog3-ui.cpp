//============================================================================
// Name        : prog3-ui.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>

#include "District.h"

using namespace std;

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

bool HandleQuery(string query)
{
	//All possible queries the program knows the answer to
	string str_to_check = query;
	string pattern = "([wW]here)(.*)(live)(.*)";
	string pattern3 = "(.*)(about)(.*)(rep)(.*)";
	string pattern2 = "(.*)(contact)(.*)";
	string pattern4 = "([wW]here)(.*)(work)(.*)";
	string pattern5 = "(.*)(committee)(.*)";
	string pattern6 = "(.*)(everything)(.*)";
	string pattern7 = "(.*)([wW])(.*)(name)(.*)";
	string pattern8 = "(.*)([wW]hat)(.*)(sponsored)(.*)";
	string pattern9 = "(.*)([wW]hat)(.*)(voting)(.*)";
	string pattern10 = "(.*)([wW]hat)(.*)(office|service|years)(.*)";
	string pattern11 = "(.*)([wW]ho)(.*)(is)(.*)(rep)(.*)";
	string pattern12 = "(.*)(phone)(.*)(number)(.*)";

	//Regex for the queries so it can check to see if what was asked matches a data set
	regex pattern_to_check1(pattern);
	regex pattern_to_check2(pattern2);
	regex pattern_to_check3(pattern3);
	regex pattern_to_check4(pattern4);
	regex pattern_to_check5(pattern5);
	regex pattern_to_check6(pattern6);
	regex pattern_to_check7(pattern7);
	regex pattern_to_check8(pattern8);
	regex pattern_to_check9(pattern9);
	regex pattern_to_check10(pattern10);
	regex pattern_to_check11(pattern11);
	regex pattern_to_check12(pattern12);

	//Program calls getInfo if it knows the answer and returns true
	if(regex_match(str_to_check, pattern_to_check1))
	{
		GetInfo("Contact Information:address, Home");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check2))
	{
		GetInfo("Contact Information");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check4))
	{
		GetInfo("Contact Information:address, Columbia");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check5))
	{
		GetInfo("Committee Assignments");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check6))
	{
		GetInfo("Everything");
		return true;
	}

	else if(regex_match(str_to_check, pattern_to_check8))
	{
		GetInfo("Sponsored Bills in the House");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check9))
	{
		GetInfo("Voting Record");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check11))
	{
		GetInfo("Contact Information:name");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check12))
	{
		GetInfo("Contact Information:phone, home");
		cout << endl;
		GetInfo("Contact Information:phone, business");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check10))
	{
		GetInfo("Service In Public Office");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check7))
	{
		GetInfo("Contact Information:name");
		return true;
	}
	else if(regex_match(str_to_check, pattern_to_check3))
	{
		GetInfo("Personal Information");
		return true;
	}
	//Program returns false indicating that it did not know the answer
	return false;


}

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
		if(district == "quit" || district == "Quit" || district == "q")
		{
			cout << "Goodbye!" << endl;
			return false;
		}
		num1 = 0;
		try
		{
			num1 = stoi(district);
			District userDistrict = {num1, "None"};
			if(userDistrict.getDistrictNum() == 5)
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
		//If prompted to quit. Will run infinitely until told to quit
		if(input == "q" || input == "Quit" || input == "quit")
		{
			cout << "Goodbye!" << endl;
			quit = true;
		}
		else
		{
			//Handle Query which will return false if the program does not have an answer
			if(HandleQuery(input) == true)
			{
				cout << endl << "Anything else I can help you with? or type quit" << endl;
			}
			else
			{
				cout << "I am sorry I do not understand. Please ask something else in the form of a question or type quit." << endl;
			}
		}
	}
	}
	return 0;
}
