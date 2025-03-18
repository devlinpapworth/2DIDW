
#include "data_handle.h"


double** data_handle::Create_DH_array(int num_DH, int x, int y)
{
	/*Creates a 2D array of drill holes. The user can choose to use example data, import data from an excel file, or manually enter data.*/


	double** DH_array = new double* [num_DH]; // creates empty 2D pointer to pointer drill hole array
	for (int i = 0; i < num_DH; i++) 
	{
		DH_array[i] = new double[3] {0.0, 0.0, 0.0};
	}

	char type;
	do 
	{
		cout << "Would you like to \n a) use an example data set, \n b) import example data set from excel (include the full path), \n c) manually enter Drill Hole data" << endl;
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
	/*Generates random drill holes for testing purposes.*/


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
	/*Imports data from excell file. Intially checks if the file contains the correct amount of data, if so it will then read in one row at a time as as string.
	Then in this string it takes out each elemnt that is seperated by a comma assinging it to the correct value in DH array.  */
	fstream myFile;

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
		getline(myFile, row); // read row from file storing as row
		stringstream ss(row); // convert row to string stream (ss)
		string value;

		for (int j = 0; j < 3; j++) // read value from row i, column j
		{
			getline(ss, value, ','); // read value from ss, store in value, split by comma
			if (j == 2 && valid_double(value)) // tests that the value is a valid double
			{
				DH_array[i][j] = stod(value);
			}
			else if (j < 2 && valid_int(value)) // tests if co-ords are ints although stored as doubles in DH_array
			{
				DH_array[i][j] = stod(value);
			}
			else
			{
				cout << "Oops, error reading Drill Hole " << i + 1 <<endl;
				
				if(j==0)
				{
					do 
					{
						string temp;
						cout << "The x coordinate is not a valid number. Manually enter below: " << endl;
						cin >> temp;
						if (valid_int(temp) && stoi(temp) > 0)
						{
							DH_array[i][j] = stod(temp);
							break;
						}
						cout << "That didn't work try again." << endl;
					} while(true);
										
				}
				else if(j==1)
				{
					do 
					{
						string temp;
						cout << "The y coordinate is not a valid number. Manually enter below: " << endl;
						cin >> temp;
						if (valid_int(temp) && stoi(temp) > 0)
						{
							DH_array[i][j] = stod(temp);
							break;
						}

						cout << "That didn't work try again." << endl;
					} while (true);
				}

				else if(j==2)
				{
					do 
					{
						string temp;
						cout << "The grade value is not a valid number. Manually enter below: " << endl;
						cin >> temp;
						if (valid_double(temp) && stod(temp) >= 0 && stod(temp) <=1.)
						{
							DH_array[i][j] = stod(temp);
							break;
						}
						cout << "That didn't work try again." << endl;
					} while (true);
				}

			}
		}
	}
	myFile.close();
}



void data_handle::manually_enter_data(double** DH_array, int num_DH) // reapting the process for each drill hole unutill required number of drill holes are entered
{
	/*Lets the user manually enter easch DH's value at a time.*/
	for (int i = 0; i < num_DH; i++) {
		cout << "Enter the data for Drill Hole " << i + 1 << endl;

		do 
		{
			string temp;
			cout << "Enter X: ";
			cin >> temp;
			if (valid_int(temp) && stod(temp) > 0) 
			{
				DH_array[i][0] = stod(temp);// stores as double in the DH array but checks if the input is an int
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
				DH_array[i][1] = stod(temp); // stores as double in the DH array but checks if the input is an int
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
				DH_array[i][2] = stod(temp); // stores as double in the DH array 
				break;
			}
			cout << "Invalid number! Try again." << endl;
		} while (true);
	}
}




void data_handle::count_rows(int num_DH, string filename)
{
	/*Checks if the excell file contains the correct number of drill holes*/
	fstream myFile;
	myFile.open(filename, fstream::in); // open file to read in

	if (myFile.fail())
	{
		cout << "Error opening file or empty file." << endl;
		exit(0);
	}

	string row;
	int num_rows = 0;
	while (getline(myFile, row))
	{
		num_rows++;
	}

	if (num_rows < num_DH)
	{
		cout << "Your excel file "<< filename<< " doesn't have the enough Drill Holes" << endl;
		exit(0);
	}
	else if (num_rows > num_DH)
	{
		cout << "Your excel file " << filename << " has to many Drill Holes" << endl;
		exit(0);
	}
	
	myFile.close();
	
}