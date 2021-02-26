//
// Program to read and process weather station data 
// Data is input one full line at a time and then processed with
// string manipulation functions
//
// It demonstrates fstream, iomanip, file open, file read, file close,
// getline, eof, substr, at, lenght and find.
//
// Actual weather station data is employed
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Variables

	string dataline = "";
	string station = "";
	string tmax_s = "", tmin_s = "";

	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;

	float tmax = 0, tmin = 0; // Real types for temps
	int bad_records = 0; // Count the records with bad data for tmax and tmin

	ifstream infile;
	ofstream outfile;

	cout << "WEATHER STATION DATA" << endl << endl;
	cout << "Open the data file." << endl << endl;
	infile.open("D:/Code Repository/C-C++/Homework_3_CS121/AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return(1);
	}
	else
	{
		cout << "Data file opened." << endl;
	}

	outfile.open("D:/Code Repository/C-C++/Homework_3_CS121/Output_AL_Weather_Station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		system("pause");
		return(1);
	}
	else
	{
		cout << "Output file opened." << endl;
	}

	cout << "Use the first line of the file to find the column positions. " << endl;
	getline(infile, dataline);
	outfile << dataline << endl;
	cout << "Line 1: " << dataline << endl;

	// Use headers to fine max and min temp columns




	pos_tmax = dataline.find("TMAX");
	if (pos_tmax <= dataline.length())
	{
		cout << "TMAX begins at column: " << pos_tmax << endl;
	}

    pos_tmin = dataline.find("TMIN");
	if (pos_tmin <= dataline.length())
	{
		cout << "TMIN begins at column: " << pos_tmin << endl;
	}


	pos_station_name = dataline.find("STATION_NAME");
	if (pos_station_name <= dataline.length())
	{
		cout << "STATION_NAME begins at column: " << pos_station_name << endl;
	}

	

	cout << "Read the second line from the file - dashes. " << endl;
    getline(infile, dataline);
	outfile << dataline << endl;
    cout << "Line 2: " << dataline << endl;

	while (!infile.eof())
	{
		// Read the lines with data

		getline(infile, dataline);

		// Read tmax and tmin as strings
		station = dataline.substr(pos_station_name,50);
		//cout << station << endl;
		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);

		// To convert the string types to int do this

		tmax = stof(tmax_s); // Convert string tmax_s to float tmax
		tmin = stof(tmin_s); // Convert string tman_s to float tmin
		

		// NOTE: to convert string to int use stoi
		//       to convert string to double use stod

		// Test for bad data flag. If good data then write to new file.

		if (tmax != -9999 && tmin != -9999 && station.find("RUSSELLVILLE") != string::npos)
			outfile << dataline << endl;
		else
			bad_records++;

	} // End While 

	// Close the files
	infile.close();
	outfile.close(); // NOTE: This program did not write any data to the output file

	cout << "There were " << bad_records << " bad records for tmax and tmin." << endl;

	cout << "\n\n";
	//system("pause");
	return 0;
}
