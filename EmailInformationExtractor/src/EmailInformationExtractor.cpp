//============================================================================
// Name        : EmailInformationExtractor.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>

#include "BaseEmailHeaderType.h"
#include "GmailHeaderType.h"
#include "OutlookHeaderType.h"

using namespace std;

void GmailExtractor(string partName)
{
	string in_file_name = "data/input.txt";
	ifstream in_myfile(in_file_name);
	string line;
	string LineWithNoPart;
	bool found = false;

	if(in_myfile.is_open())
	{
		while(getline(in_myfile, line))
		{
			string str_to_check = line;
			string pattern = partName + "(.*)";
			regex pattern_to_check(pattern);
			if(regex_match(str_to_check, pattern_to_check))
			{
				LineWithNoPart = line.substr(partName.length()+2);
				cout << LineWithNoPart << endl;
				found = true;
			}
		}
		if(found == false)
		{
			cout << "No part found with your input." << endl;
		}
		in_myfile.close();
	}
}
void OutlookExtractor(string partName)
{
	string in_file_name = "data/input.txt";
	ifstream in_myfile(in_file_name);
	string line;
	string LineWithNoPart;
	bool found = false;

		if(in_myfile.is_open())
		{
			while(getline(in_myfile, line))
			{
				string str_to_check = line;
				string pattern = partName + "(.*)";
				regex pattern_to_check(pattern);
				if(regex_match(str_to_check, pattern_to_check))
				{
					LineWithNoPart = line.substr(partName.length()+2);
					cout << LineWithNoPart << endl;
					found = true;
				}
			}
			if(found == false)
			{
				cout << "No part found with your input." << endl;
			}
			in_myfile.close();
		}
}
int main()
{
	cout << "Enter part name:" << endl;
	string partName;
	cin >> partName;

	string in_file_name = "data/input.txt";
	ifstream in_myfile(in_file_name);
	string line;

	if (in_myfile.is_open())
	{
		getline(in_myfile, line);
		string str_to_check = line;
		string pattern = "(.*)(gmail)(.*)";
		regex pattern_to_check(pattern);

		if(regex_match(str_to_check, pattern_to_check))
		{
			//PROGRAM NOW KNOWS IT IS GMAIL
			GmailExtractor(partName);
		}
		pattern = "(.*)(outlook)(.*)";
		regex pattern_to_check2(pattern);

		if(regex_match(str_to_check, pattern_to_check2))
		{
			//PROGRAM NOW KNOWS IT IS OUTLOOK;
			OutlookExtractor(partName);
		}

		in_myfile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}

	return 0;
}
