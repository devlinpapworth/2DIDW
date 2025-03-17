
#include "data_handle.h"


double** data_handle::Create_DH_array(int num_DH, int x, int y)
{
	double** DH_array = new double* [num_DH];
	for (int i = 0; i < num_DH; i++) 
	{
		DH_array[i] = new double[3] {0.0, 0.0, 0.0}; // creates empty drill hole array
	}

	char type;
	do 
	{
		cout << "Would you like to \n a) use an example data set, \n b) import example data set from excel (include full path), \n c) manually enter Drill Hole data" << endl;
		cin >> type;

		if (type == 'a') 
		{
			use_example_data(DH_array, num_DH, x, y); //private member function only called if user selects this option
			break;
		}
		else if (type == 'b') 
		{
			import_data_from_excel(DH_array, num_DH); //private member function only called if user selects this option
			break;
		}
		else if (type == 'c') 
		{
			manually_enter_data(DH_array, num_DH); //private member function only called if user selects this option
			break;
		}
		else 
		{
			cout << "Invalid choice. Try again."; // loop until a valid choice is made
		}
	} while (true); 



	// Display entered values
	cout << "\nDrill Hole Data:\n";

	for (int i = 0; i < num_DH; i++) 
	{
		cout << "DH " << i + 1 << ": X = " << DH_array[i][0] << ", Y = " << DH_array[i][1] << ", Grade = " << DH_array[i][2] << endl;
	}

	return (DH_array);
	
}


void data_handle::use_example_data(double** DH_array, int num_DH, int x, int y) 
{
	cout << " Please note this is adapted from https://www.w3schools.com/cpp/cpp_howto_random_number.asp. This has only been used to test the code with different values and is not a core function of my code" << endl;
	// Example Drill Holes generated using random number generator.
	// Please note this is adapted from https://www.w3schools.com/cpp/cpp_howto_random_number.asp.
	// This has only been used to test the code with different values and is not a core function of my code.

	srand(time(0)); 
	for (int i = 0; i < num_DH; i++)
	{
		
		int randomx = rand() % x;
		DH_array[i][0] = randomx;
		int randomy = rand() % y;
		DH_array[i][1] = randomy;
		double randomval = ((double)rand() / RAND_MAX) * 0.1; 
		DH_array[i][2] = randomval;
	}
}




void data_handle::import_data_from_excel(double** DH_array, int num_DH)
{


	string filename;
	cout << "Enter the file name: " << endl;
	cin >> filename;
	count_rows(num_DH, filename);

	myFile.open(filename, fstream::in); // open file to read in
	string row;

	if (myFile.fail())
	{
		cout << "Error opening file or empty file." << endl;
		exit(0);
	}

	//do
	//{
		count_rows(num_DH, filename);
	//} while(true);

	for (int i = 0; i < num_DH; i++) 
	{
		getline(myFile, row); // read row i
		stringstream ss(row); // convert row to string stream
		string value;

		for (int j = 0; j < 3; j++) 
		{
			getline(ss, value, ','); // read value from row i, column j
			if (valid_double(value))
			{
				DH_array[i][j] = stod(value);
			}
			else
			{
				cout << "Oops, error reading Drill Hole: " << i + 1 <<endl;
				string temp;
				if(j==0)
				{
					do 
					{
						cout << "The x coordinate is not a valid number. Manually enter bellow: " << endl;
						cin >> temp;
						if (valid_double(temp) && stod(temp) > 0)
						{
							DH_array[i][j] = stod(temp);
							break;
						}
					} while(true);

					cout << "That didn't work try again." << endl;
				}
				else if(j==1)
				{
					do 
					{
						cout << "The y coordinate is not a valid number. Manually enter bellow: " << endl;
						cin >> temp;
						if (valid_double(temp) && stod(temp) > 0)
						{
							DH_array[i][j] = stod(temp);
							break;
						}
					} while (true);

					cout << "That didn't work try again." << endl;
				}
				else if(j==2)
				{
					do 
					{
						cout << "The grade value is not a valid number. Manually enter bellow: " << endl;
						cin >> temp;
						if (valid_double(temp) && stod(temp) >= 0 && stod(temp) <=1.)
						{
							DH_array[i][j] = stod(temp);
							break;
						}

					} while (true);
					cout << "That didn't work try again." << endl;
				}

			}
		}
	}
	myFile.close();
}



void data_handle::manually_enter_data(double** DH_array, int num_DH) // reapting the process for each drill hole unutill required number of drill holes are entered
{
	for (int i = 0; i < num_DH; i++) {
		cout << "Enter the data for Drill Hole " << i + 1 << endl;

		do 
		{
			string temp;
			cout << "Enter X: ";
			cin >> temp;
			if (valid_int(temp) && stod(temp) > 0) 
			{
				DH_array[i][0] = stod(temp);
				break;
			}
			cout << "Invalid number! Try again." << endl;
		} while (true);


		do 
		{
			string temp;
			cout << "Enter Y: ";
			cin >> temp;
			if (valid_int(temp) && stod(temp) > 0) 
			{
				DH_array[i][1] = stod(temp);
				break;
			}
			cout << "Invalid number! Try again." << endl;
		} while (true);


		do 
		{
			string temp;
			cout << "Enter Value: ";
			cin >> temp;
			if (valid_double(temp) && stod(temp) >= 0 && stod(temp) <= 1) 
			{
				DH_array[i][2] = stod(temp);
				break;
			}
			cout << "Invalid number! Try again." << endl;
		} while (true);
	}
}




int data_handle::count_rows(int num_DH, string filename)
{
	
	myFile.open(filename, fstream::in); // open file to read in


	string row;
	int num_rows = 0;
	while (getline(myFile, row))
	{
		num_rows++;
	}
	cout << num_rows;
	cout << num_DH;
	if (num_rows != num_DH)
	{
		cout << "Your excell file "<< filename<< " doesn't have the same number of drill holes that you entered." << endl;
		exit(0);
	}
	myFile.close();
	return(0);
}