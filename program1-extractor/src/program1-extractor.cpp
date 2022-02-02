//============================================================================
// Name        : program1-extractor.cpp
// Author      : Joshua Braun
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void ReadDistrict(string x) {

	string file_name = "data/"  + x + "data.txt";
	string out_file_name = "data/" + x + "output.txt";

	string line;

	ifstream myfile(file_name);
	ofstream out_myfile(out_file_name);

	if (myfile.is_open())
	{
		if(out_myfile.is_open())
		{
			int lineCount = 0;
			int totalwordCount = 0;
			int totalcharCount = 0;
			while (getline(myfile, line))
			{
				lineCount++;

				// Now parse each line for segments with different data types
				stringstream lineStream(line);
				int wordCount = 0;
				string word;

				while (lineStream >> word)
				{
					wordCount++;
					totalwordCount++;

					//print word to output
					out_myfile << word << "\t";

					for(char a: word)
					{
						totalcharCount++;
					}
				} // end - while

				//finish line
				out_myfile << "\n";

			} // end- while

			//Display file statistics
			cout << "Lines in file: " << lineCount << '\n';
			cout << "Words in file: " << totalwordCount << '\n';
			cout << "Characters in file: " << totalcharCount << '\n';


			out_myfile.close();
		}
		myfile.close();
	}
	else
	cout << "Unable to open file - " << file_name << endl;

}

int main()
{
	string district;
	cout << "Please enter district name: " << endl;
	getline(cin, district);

	//Check to see if district 9
	if(district.find('9') != string::npos)
	{
		ReadDistrict("District9");
	}
	else
	{
		cout << "No local file available" << endl;
	}

	return 0;
}
