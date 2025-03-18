#include<iostream>
#include<fstream>
#include"IDW_Functions.h"
#include"data_handle.h"
#include"ask_usr.h"
#include"Error_handler.h"
#include"run_py_script.h"
#include<string>

#pragma once


using namespace std;



int main(void)
{
	ask_usr user;
	data_handle data;
	Error_check check;
	IDW func;// calling the classes into main function
	
	
			
	cout << "\n\t\t\tWelcome to the Inverse Distance Weighting (IDW) program.\n\n" << endl;

	double power = user.get_power();
			
	int grid_x, grid_y;
	user.grid_check(grid_x, grid_y);


	int num_DH = user.get_num_DH(grid_x, grid_y);

	double** input_array = data.Create_DH_array(num_DH, grid_x, grid_y); // creating the array to store the data

	input_array = check.all_check(grid_x, grid_y, input_array, num_DH); // checking all the data before running the IDW function

	cout << "\n.............................................\n";
	func.IDW_top_func(grid_x, grid_y, power, input_array, num_DH);  // calling the IDW function
	cout << "\n.............................................\n";
	
	run_py();

	cout << "\n IDW model is complete attempting to clear data \n";

	for (int i = 0; i < num_DH; i++)
	{
		delete[] input_array[i];
	}
	delete[] input_array;

	cout << "\n Succes clearing data. \n";

}

