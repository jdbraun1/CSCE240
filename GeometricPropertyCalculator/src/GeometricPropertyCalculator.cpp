//============================================================================
// Name        : GeometricPropertyCalculator.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;


void CalculateArea()
{
	int num1 =0; int num2 = 0;
	string in_file_name = "data/input.txt";
	string out_file_name = "data/output.txt";

	string line;
	ifstream in_myfile(in_file_name);
	ofstream out_myfile(out_file_name);

	if (in_myfile.is_open())
	{
		if(out_myfile.is_open())
		{
			while (getline(in_myfile, line))
			{

				stringstream lineStream(line);
				string word;
				int wordcount = 0;
				bool RECTcalc = false; bool CIRCcalc = false;
				while(lineStream >> word)
				{

					if(word == "TRIANGLE")
					{
						out_myfile << "TRIANGLE AREA: Not enough information to calculate" << endl;
					}
					else if(word == "RECTANGLE")
					{
						RECTcalc = true;
					}
					else if(word == "CIRCLE")
					{
						CIRCcalc = true;
					}
					else if(RECTcalc == true)
					{
						if(num1 == 0)
						{
							num1 = stoi(word);
						}
						else
						{
						num2 = stoi(word);
						out_myfile << "RECTANGLE AREA: " << num1*num2 << endl;
						RECTcalc = false;
						}
					}
					else if(CIRCcalc == true)
					{
						num1 = stoi(word);
						int rad2 = num1*num1;
						out_myfile << "CIRCLE AREA: " << rad2*M_PI << endl;
						CIRCcalc = false;
					}
					wordcount += 1;
				}
				if (RECTcalc == true)
				{
					out_myfile << "RECTANGLE AREA: Insufficient information" << endl;
				}
				if(CIRCcalc == true)
				{
					out_myfile << "CIRCLE AREA: Insufficient information" << endl;
				}

			}
			out_myfile.close();
		}
		else
		{
			cout << "Unable to output file - " << out_file_name << endl;
		}
		in_myfile.close();

	} else
		cout << "Unable to open file - " << in_file_name << endl;
}
void CalculatePerimeter()
{
		int num1 =0; int num2 = 0;
		string in_file_name = "data/input.txt";
		string out_file_name = "data/output.txt";

		string line;
		ifstream in_myfile(in_file_name);
		ofstream out_myfile(out_file_name);

		if (in_myfile.is_open())
		{
			if(out_myfile.is_open())
			{
				while (getline(in_myfile, line))
				{

					stringstream lineStream(line);
					string word;
					int wordcount = 0;
					bool RECTcalc = false; bool CIRCcalc = false; bool TRIcalc = false;
					while(lineStream >> word)
					{

						if(word == "TRIANGLE")
						{
							TRIcalc = true;
						}
						else if(word == "RECTANGLE")
						{
							RECTcalc = true;
						}
						else if(word == "CIRCLE")
						{
							CIRCcalc = true;
						}
						else if(RECTcalc == true)
						{
							if(num1 == 0)
							{
								num1 = stoi(word);
							}
							else
							{
							num2 = stoi(word);
							out_myfile << "RECTANGLE Perimeter: " << num1*2+num2*2 << endl;
							RECTcalc = false;
							num1 = 0; num2 = 0;
							}
						}
						else if(CIRCcalc == true)
						{
							num1 = stoi(word);
							out_myfile << "CIRCLE Perimeter: " << 2*num1*M_PI << endl;
							CIRCcalc = false;
							num1 = 0;
						}
						else if(TRIcalc == true)
						{
							if(num1 == 0)
							{
								num1 = stoi(word);
							}
							else if(num2 == 0)
							{
								num2 = stoi(word);
							}
							else
							{
								int num3 = stoi(word);
								out_myfile << "TRIANGLE Perimeter: " << num1+num2+num3 << endl;
								TRIcalc = false;
								num1 = 0; num2 = 0; num3 = 0;
							}
						}
						wordcount += 1;
					}
					if (RECTcalc == true)
					{
						out_myfile << "RECTANGLE Perimeter: Insufficient information" << endl;
					}
					if(CIRCcalc == true)
					{
						out_myfile << "CIRCLE Perimeter: Insufficient information" << endl;
					}
					if(TRIcalc == true)
					{
						out_myfile << "TRIANGLE Perimeter: Insufficient information" << endl;
					}

				}
				out_myfile.close();
			}
			else
			{
				cout << "Unable to output file - " << out_file_name << endl;
			}
			in_myfile.close();

		} else
			cout << "Unable to open file - " << in_file_name << endl;
}
int main(int argc, char *argv[])
{
	cout << "Program name is: " << argv[0] << endl;
	char command = 0;

	if (argc >= 2)
	{
		command = *argv[1];
		cout << "Command to run is: " << command << endl;

		if(command == '1')
		{
			CalculateArea();
		}
		else if(command == '2')
		{
			CalculatePerimeter();
		}
		else
		{
			cout << "Invalid command" << endl;
		}
	}
	else
	{
		cout << "No command entered";
	}

	return 0;
}
