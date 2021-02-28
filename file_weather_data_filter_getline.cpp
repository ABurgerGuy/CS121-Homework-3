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

string centerText (string text);

int main(void)
{
	// Variables
	string centeredStation = "";
	string dataline = "";
	string station = "";
	string tmax_s = "", tmin_s = "", prcp_s = "";
	string date_s = "";

	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;
	unsigned int pos_prcp = 0;

	float tmax = 0, tmin = 0, prcp = 0; // Real types for temps
	int bad_records = 0;				// Count the records with bad data for tmax and tmin

	ifstream infile;
	ofstream outfile;
	ofstream column5file;
	

	cout << "WEATHER STATION DATA" << endl
		 << endl;
	cout << "Open the data file." << endl
		 << endl;
	infile.open("D:/Code_Repository/C-C++/Homework_3_CS121/textFiles/AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		//system("pause");
		return (1);
	}
	else
	{
		cout << "Data file opened." << endl;
	}

	outfile.open("D:/Code_Repository/C-C++/Homework_3_CS121/textFiles/Filtered_AL_Weather_Station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		//system("pause");
		return (1);
	}
	else
	{
		cout << "Output file opened." << endl;
	}

	column5file.open("D:/Code_Repository/C-C++/Homework_3_CS121/textFiles/weather_station_five_column.txt");
	if (!column5file)
	{
		cout << "Unable to open the output file. " << endl;
		//system("pause");
		return (1);
	}
	else
	{
		cout << "Output column file opened." << endl;
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

	pos_prcp = dataline.find("PRCP");
	if (pos_prcp <= dataline.length())
	{
		cout << "PRCP begins at column: " << pos_prcp << endl;
	}

	pos_date = dataline.find("DATE");
	if (pos_date)
	{
		cout << "DATE begins at column : " << pos_date << endl;
	}
	

		//TODO: implement what will be filled on first line of the new file
	cout << "Column File Line 1: " << setw(50) << centerText("STATION") << setw(10) << centerText("DATE") << endl;
	column5file << setw(50) << centerText("STATION") << setw(10) << centerText("DATE") << endl;

	cout << "Read the second line from the file - dashes. " << endl;
	getline(infile, dataline);
	outfile << dataline << endl;
	cout << "Line 2: " << dataline << endl;

	while (!infile.eof())
	{
		// Read the lines with data

		getline(infile, dataline);

		// Read tmax and tmin as strings
		//cout << station << endl;
		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);
		station = dataline.substr(pos_station_name, 50);
		prcp_s = dataline.substr(pos_prcp, 5);
		centeredStation = centerText(station);
		// To convert the string types to int do this

		tmax = stof(tmax_s); // Convert string tmax_s to float tmax
		tmin = stof(tmin_s); // Convert string tman_s to float tmin
		prcp = stof(prcp_s);

		// NOTE: to convert string to int use stoi
		//       to convert string to double use stod

		// Test for bad data flag. If good data then write to new file.

		if (tmax != -9999 && tmin != -9999 && prcp != -9999)
		{
			outfile << dataline << endl;
			column5file << setw(50) <<centeredStation <<endl;
		}
		else
			bad_records++;

	} // End While

	// Close the files
	infile.close();
	outfile.close(); // NOTE: This program did not write any data to the output file
	column5file.close();

	cout << "There were " << bad_records << " bad records for tmax and tmin." << endl;

	cout << "\n\n";
	//system("pause");
	return 0;
}



//center text function
//this also removes all the spaces before other characters
string centerText (string text)
{
    string centeredString = "";
	bool charFound = false;
	int centerSize = 50;

		for (int i = 0; i < centerSize; i++)
		{
			if (text[i] != ' ')
			{
				charFound = true;
			}
			if (charFound == true)
			{
				text = text.substr(i);
				break;
			}
		}

        for(int j=0; j<(centerSize-(text.length()/sizeof(text[0])))/2; j++)
		{
        	centeredString += " ";  
        }
		centeredString += text;
		
        return centeredString;
}
