#include"run_py_script.h"



/*Runs the external python script not included in my assesed work and is used to neatly display the data.*/

void run_py()
{
	char Y_N;
	cout << "Would you like to diplay the data in a block model? " << endl;
	cout << "y/n" << endl;
	cin >> Y_N;


	if (Y_N == 'y' || Y_N == 'Y')
	{
		cout << "Please note this will run a Python script that assigns a color value to each grid square corresponding to the value calculated by my code."<<
			" It reads in the Excel file generated by the IDW model. This Python script has been adapted from online resources and is not a part of my assessed work." << endl;
		
		cout << "Running Python script...\n";

		int result = system("python displa_DHDB.py");

		if (result == 0)
		{
			cout << "Python script executed successfully.\n";
		}
		else
		{
			cout << "Failed to execute Python script.\n";
		}
	}

}