#include<iostream>
#include<fstream>
#include"IDW_Functions.h"
#include"data_handle.h"
#include"ask_usr.h"
#include"Error_handler.h"
#include<string>

#include <cstdlib> // For system()
#pragma once


using namespace std;



int main(void)
{
	ask_usr user;
	data_handle data;
	Error_check check;// calling the classes in the main function
	cout << "Welcome to the Inverse Distance Weighting (IDW) program." << endl;

	double power = user.get_power();

	// asks user for power value and repeats untill in correct range
		
	int grid_x, grid_y;

	do 
		{
			user.grid_size(grid_x, grid_y);
			char Y_N;
			cout << "Your grid dimensions are " << grid_x << "x by " << grid_y << "y" << endl;
		
			cout << "Is this correct (y/n): " << endl;
			cin >> Y_N;

			if (Y_N == 'y' || Y_N =='Y')
			{
				cout << "\nAmazing! Lets start." << endl;
				break;
			}

			cout << "Oh no, lets try again." << endl;

			
		}while (true);

	string temp;
	do {
		cout << "How many Drill holes do you want to enter? " << endl;
		cin >> temp;
		if (valid_int(temp) && stod(temp)>0)
		{
			break;
			
		}
		cout << "Oops, looks like that entry didnt work. Try again: ";
	} while (true);

	int num_DH = stod(temp);

	double** input_array = data.Create_DH_array(num_DH, grid_x, grid_y);

	cout << "Before we start lets check for errors in the data. " << endl;
	cout << "\n.............................................\n";
	input_array = check.valid_DH_values(input_array, num_DH);
	cout << "\n.............................................\n";
	input_array = check.repeat_DH_xy(input_array, num_DH);
	cout << "\n.............................................\n";
	input_array = check.grid_greater_than_DH(grid_x, grid_y, input_array, num_DH);
	cout << "\n.............................................\n";

	cout << "\nEverything seems in order lets begin." << endl; 
	
	cout << "\n.............................................\n";
	IDW_top_func(grid_x, grid_y, power, input_array, num_DH); 
	cout << "\n.............................................\n";
	
	char Y_N;
	cout << "Would you like to diplay the data in a block model? " << endl;
	cout << "y/n" << endl;
	cin >> Y_N;


	if (Y_N == 'y' || Y_N == 'Y')
	{
		cout << "Please note this will run a python script to show the resuluts graphically and that is not my own work. It has been generated with online resources and chat GPT." << endl;
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
	
	

	cout << "\n Complete, clearing data \n";
	for (int i = 0; i < num_DH; i++)
	{
		delete[] input_array[i];
	}
	delete[] input_array;

	cout << "\n succes \n";

}
