#include"run_py_script.h"


void run_py()
{
	char Y_N;
	cout << "Would you like to diplay the data in a block model? " << endl;
	cout << "y/n" << endl;
	cin >> Y_N;


	if (Y_N == 'y' || Y_N == 'Y')
	{
		cout << "Please note this will run a python script that asign a colour value to each grid square corrosponding to the value calculated by my code. It reads in the excel file generated by the IDW model. This python scipt has been adapted from online resourrces and is not a part of my assesed work." << endl;
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