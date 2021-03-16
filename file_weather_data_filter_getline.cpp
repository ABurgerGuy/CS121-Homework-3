//
// Program to read and process weather station data
// Data is input one full line at a time and then processed with
// string manipulation functions
//
// 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string centerText(string text, int size);

float ctof(float celsius);

int main(void)
{
	// Variables
	string centeredStation = "";
	string dataline = "";
	string station = "";
	string tmax_s = "", tmin_s = "", prcp_s = "", date_s = "";
	string desiredStation = "";

	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;
	unsigned int pos_prcp = 0;
	int year, month, day;
	int year1, month1, day1;
	int year2, month2, day2;
	int newMax = 0, newMaxStat = 0;
	int newMin = 900, newMinStat = 900;
	int numOfStats = 1;
	int numOfStat = 0;
	int count = 1;
	int bad_records = 0;

	float tempTotal = 0;
	float totalsOfTemps = 0, totalPrecip = 0, betweenDatePrecip = 0;
	float tmax = 0, tmin = 0, prcp = 0;

	bool addToList = true;

	ifstream infile;
	ofstream outfile;
	ofstream column5file;

	cout << "WEATHER STATION DATA" << endl << endl;
	infile.open("./textFiles/AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		return (1);
	}
	else
	{
		cout << "Data file opened." << endl;
	}

	outfile.open("./textFiles/Filtered_AL_Weather_Station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		return (1);
	}
	else
	{
		cout << "Output file opened." << endl;
	}

	column5file.open("./textFiles/weather_station_five_column.txt");

	if (!column5file)
	{
		cout << "Unable to open the output file. " << endl;
		return (1);
	}
	else
	{
		cout << "Output column file opened." << endl;
	}

	getline(infile, dataline);
	outfile << dataline << endl;

	pos_tmax = dataline.find("TMAX");
	if (pos_tmax <= dataline.length())
	{
		//cout << "TMAX begins at column: " << pos_tmax << endl;
	}

	pos_tmin = dataline.find("TMIN");
	if (pos_tmin <= dataline.length())
	{
		//cout << "TMIN begins at column: " << pos_tmin << endl;
	}

	pos_station_name = dataline.find("STATION_NAME");
	if (pos_station_name <= dataline.length())
	{
		//cout << "STATION_NAME begins at column: " << pos_station_name << endl;
	}

	pos_prcp = dataline.find("PRCP");
	if (pos_prcp <= dataline.length())
	{
		//cout << "PRCP begins at column: " << pos_prcp << endl;
	}

	pos_date = dataline.find("DATE");
	if (pos_date)
	{
		//cout << "DATE begins at column : " << pos_date << endl;
	}

	column5file << left << setw(52) << centerText("STATION", 50) << setw(13) 
	<< centerText("DATE", 10) << setw(9) << centerText("PRCP", 8) << setw(9) 
	<< centerText("TMAX", 4) << setw(10) << centerText("TMIN", 5) << endl;

	getline(infile, dataline);
	outfile << dataline << endl;

	/*
	TODO: implement user input functionality for: 
		* Total Precipitation over a range of dates(done)
		* Selection System(done)
		* Total Precipitation from all stations for a single day(done)
		* Total Precipitation by Station for March(done)
		* Temperature Extremes and Average by Station(done)
		* Temperature Extremes and Average by Station over a range of dates(done)
	*/
	int userOption;
	cout << "Welcome!\n please enter your desired option:";
	cout << "\n1. Total Precipitation over a range of dates";
	cout << "\n2. Total Precipitation from all stations for a single day";
	cout << "\n3. Total Precipitation by Station for March"; 
	cout << "\n4. Temperature Extremes and Average by Station";
	cout << "\n5. Temperature Extremes and Average by Station over a range of dates";

	cin >> userOption;
	
	//give user proper input for selection
	switch (userOption)
	{
	case 1:
		cout << "enter a range of dates in the form YYYY MM DD YYYY MM DD : ";
		cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
		cout << year1 << " " << month1 << " " << day1 << " " << year2 << " " << month2 << " " << day2 << endl;
	break;
	case 2:
		cout << "enter the day in the form YYYY MM DD : ";
		cin >> year1 >> month1 >> day1;
		cout << year1 << " " << month1 << " " << day1 << endl;
	break;
	case 3:
		cout << "enter your desired station : ";
		cin.ignore(1);
		getline(cin, desiredStation);
	break;
	case 4:
		cout << "enter your desired station : ";
		cin.ignore(1);
		getline(cin, desiredStation);
	break;
	case 5:
		cout << "enter your desired station : ";
		cin.ignore(1);
		getline(cin, desiredStation);
		cout << "enter the range of dates in the form YYYY MM DD YYYY MM DD : ";
		cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2;
		cout << year1 << " " << month1 << " " << day1 << " " << year2 << " " << month2 << " " << day2 << endl;
	break;
	
	default:
		cout << "No valid option was picked. Good bye!" << endl;
		break;
	}

	while (!infile.eof())
	{
		getline(infile, dataline);

		date_s = dataline.substr(pos_date, 8);
		tmax_s = dataline.substr(pos_tmax, 5);
		tmin_s = dataline.substr(pos_tmin, 5);
		station = dataline.substr(pos_station_name, 50);
		prcp_s = dataline.substr(pos_prcp, 5);

		tmax = stof(tmax_s);
		tmin = stof(tmin_s);
		prcp = stof(prcp_s);
		year = stoi(date_s.substr(0, 4));
		month = stoi(date_s.substr(4, 2));
		day = stoi(date_s.substr(6, 2));
		date_s = to_string(year) + ' ' + date_s.substr(4, 2) + ' ' + date_s.substr(6, 2);
		
		//filter bad data points out
		if (tmax != -9999 && tmin != -9999 && prcp != -9999)
		{
			//filter data based on user input
			if (userOption == 1 && day >= day1 && day <= day2)
			{
				cout << station << " " << date_s <<  endl;
				betweenDatePrecip += prcp;
			}
			else if (userOption == 2 && day1 == day)
			{
				cout << station << endl;
				betweenDatePrecip += prcp;
			}
			else if (userOption == 3 && station.find(desiredStation) != string::npos)
			{
				cout << station << " " << date_s << endl;
				betweenDatePrecip += prcp;
			}
			else if (userOption == 4 && station.find(desiredStation) != string::npos)
			{
				//check for min and max temps and also divide the sum of those 2 by 2
				cout << station << " " << date_s << endl;
				if (tmax >= newMaxStat)
				{
					newMaxStat = tmax;
				}
				if (tmin <= newMinStat)
				{
					newMinStat = tmin;
				}
				
				totalsOfTemps += (tmax+tmin)/2; 
				numOfStats++;

			}
			else if (userOption == 5 && day >= day1 && day <= day2 && station.find(desiredStation) != string::npos)
			{
				//same as above but only for certain stations defined by the user
				cout << station << " " << date_s << endl;
				if (tmax >= newMaxStat)
				{
					newMaxStat = tmax;
				}
				if (tmin <= newMinStat)
				{
					newMinStat = tmin;
				}
				
				totalsOfTemps += (tmax+tmin)/2; 
				numOfStats++;
				
			}

				column5file << setw(52) << left << centerText(station, 50) << right << setw(10) << date_s << left << "     " << fixed << setprecision(2) << setw(7) << prcp << setw(9) << ctof(tmax) << setw(10) << ctof(tmin) << endl;
				totalPrecip += prcp;

				if (tmax >= newMax)
				{
					newMax = tmax;
				}

				if (tmin <= newMin)
				{
					newMin = tmin;
				}
			
			outfile << dataline << endl;
		}
		else
			bad_records++;
	} // End While

	// Close the files
	infile.close();
	outfile.close(); 
	column5file.close();

	cout << "There were " << bad_records << " bad records for tmax, tmin and prcp." << endl;

	cout << "\n\n";

	cout << "Max Tempurature across all valid data points in " << desiredStation << " : " << newMax << endl;
	cout << "Min Tempurature across all valid data points in " << desiredStation << " : " << newMin << endl;
	cout << "Total precipitation across all valid data points in " << desiredStation << " : " << totalPrecip << endl;
	

	if (userOption == 1)
	{
	cout << fixed << "total precipitation from " << year1 << " " << month1 << " " << day1 << " to " << year2 << " " 
	<< month2 << " " << day2 << " is " << betweenDatePrecip << endl;
	} else if (userOption == 2)
	{
		cout << fixed << "total precipitation from all stations for " << year1 << " " << month1 << " " << day1 
		<< " is " << betweenDatePrecip << endl;
	} else if (userOption == 3)
	{
		cout << fixed << "total preciptitation from " << desiredStation << " is " << betweenDatePrecip << endl;
	} else if (userOption == 4)
	{
		cout << fixed << setprecision(2) << "In " << desiredStation << ", the max temp was " << newMaxStat/10.0 
		<< " degrees Celcius, the min temp was " << newMinStat/10.0 << " degrees Celcius, the average temp was " 
		<< ((totalsOfTemps/10)/numOfStats) << " degrees Celcius."<< endl;
	} else if (userOption == 5)
	{

		cout << fixed << setprecision(2) << "In " << desiredStation << " from " << year1 << " " << month1 << " " 
		<< day1 << " to " << year2 << " " << month2 << " " << day2 << " the max temp was " << newMaxStat/10 
		<< " the min temp was " << newMinStat/10 << " the average temp was " << ((totalsOfTemps/10)/numOfStats) 
		<< " degrees Celcius." << endl;
	}

	cout << endl << endl;
	return 0;
}

//center text function
string centerText(string text, int size)
{
	string centeredString = "";
	bool charFound = false;
	int centerSize = size;

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
	for (int j = 0; j < (centerSize - (text.length() / sizeof(text[0]))) / 2; j++)
	{
		centeredString += " ";
	}

	centeredString += text;

	return centeredString;
}

float ctof(float celsius) 
{
    return (celsius / 10) * (9.0 / 5.0) + 32;
}
