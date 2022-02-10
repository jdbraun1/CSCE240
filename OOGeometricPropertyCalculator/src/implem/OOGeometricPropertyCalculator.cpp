//============================================================================
// Name        : OOGeometricPropertyCalculator.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <regex>
using namespace std;
#include <fstream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
Rectangle R;
Circle C;
Triangle T;

void Calculate()
{

	    string in_file_name = "data/input.txt";
		string out_file_name = "data/output.txt";

		string line;
		ifstream in_myfile(in_file_name);
		ofstream out_myfile(out_file_name);

		int linecount = 0;
		int shape = 0;

		if (in_myfile.is_open())
		{
			if(out_myfile.is_open())
			{
				while (getline(in_myfile, line))
				{
					linecount++;
					stringstream lineStream(line);
					string word;
					int num1 = 0;
					int num2 = 0;
					int num3 = 0;
					while(lineStream >> word)
					{
						if(shape == 1)
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
								shape = 0;
								num3 = stoi(word);
								T.setPerimeter(num1+num2+num3);
							}

						}
						else if(shape == 2)
						{
							shape = 0;
							num1 = stoi(word);
							int rad2= num1*num1;
							C.setArea(rad2*M_PI);
							C.setPerimeter(2*num1*M_PI);
							num1 = 0;

						}
						else if(shape == 3)
						{
							if(num1 == 0)
							{
								num1 = stoi(word);
							}
							else
							{
								shape = 0;
								num2 = stoi(word);
								R.setArea(num1*num2);
								R.setPerimeter(num1*2 + num2*2);
								num1 = 0; num2 = 0;
							}
						}
						else
						{
							if(word == "TRIANGLE")
							{
								shape = 1;
							}
							if(word == "CIRCLE")
							{
								shape = 2;

							}
							if(word == "RECTANGLE")
							{
								shape = 3;
							}
						}
					}
				}
				out_myfile.close();
			}
			else
			{
				cout << "Unable to output file - " << out_file_name << endl;
			}

			in_myfile.close();
		}
		else
		cout << "Unable to open file - " << in_file_name << endl;
}
int main(int argc, char *argv[])
{
	cout << "Program name is: " << argv[0] << endl;
	char command = 0;
	Calculate();
	string out_file_name = "data/output.txt";

	ofstream out_myfile(out_file_name);

	if (argc == 2)
	{
		command = *argv[1];
		cout << "Command to run is: " << command << endl;

		if(command == '1')
		{
			if(out_myfile.is_open())
			{
				out_myfile << "TRIANGLE AREA: " << T.getErrorMessage() << endl;
				out_myfile << "CIRCLE AREA: " << C.getArea() << endl;
				out_myfile << "RECTANGLE AREA: " << R.getArea() << endl;
			}
		}
		else if(command == '2')
		{
			if(out_myfile.is_open())
			{
				out_myfile << "TRIANGLE AREA: " << T.getPerimeter() << endl;
				out_myfile << "CIRCLE AREA: " << C.getPerimeter() << endl;
				out_myfile << "RECTANGLE AREA: " << R.getPerimeter() << endl;
			}
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

	out_myfile.close();
	return 0;
}
