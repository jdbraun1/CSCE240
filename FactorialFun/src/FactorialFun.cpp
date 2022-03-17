//============================================================================
// Name        : FactorialFun.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;

long long factorial(int n)
{
	if (n == 2)
	{
		return n;
	}
	  return n * factorial(n-1);
}

int main(int argc, char** argv)
{


	string line;
	int num1 = 0; int num2 = 0;
	long long fact = 0;
	long long fact2 = 0;
	long long fact3 = 0;
	long long result = 0;

	if(argc == 2)
	{
		try
		{

			num1 = stoi(argv[1]);
			auto start = std::chrono::steady_clock::now();
			fact = factorial(num1);
			auto  end = std::chrono::steady_clock::now();

			std::chrono::duration<double> diff_in_seconds = end - start;

			cout << fact << endl;
			cout << "elapsed time (in sec): " << diff_in_seconds.count() << "s\n";
		}
		catch(const invalid_argument& ia)
		{
			cout << "must enter numbers" << endl;
		}
	}
	else if(argc == 3)
	{
		try
		{
			num1 = stoi(argv[1]);
			num2 = stoi(argv[2]);

			if(num1 <= num2)
			{
				cout << "incorrect input first number has to be greater than second" << endl;
			}
			else if(num1 != 0 && num2 != 0)
			{
				auto start = std::chrono::steady_clock::now();
				fact = factorial(num1);
				fact2 = factorial(num2);
				fact3 = factorial(num1 - num2);
				result = fact/(fact2*fact3);
				auto  end = std::chrono::steady_clock::now();
				std::chrono::duration<double>diff_in_seconds = end - start;
				cout << result << endl;
				cout << "elapsed time (in sec): " << diff_in_seconds.count() << "s\n";
			}
			else
			{
				cout << "numbers can not be 0" << endl;
			}
		}
		catch(const invalid_argument& ia)
		{
			cout << "Must enter numbers" << endl;
		}


	}
	else
	{
		cout << "invalid number of commands" << endl;
	}
	return 0;
}
