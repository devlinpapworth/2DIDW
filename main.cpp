#include<iostream>
#include<fstream>
#include"IDW_Functions.h"
#include"data_handle.h"
#include"ask_usr.h"
#include"Error_handler.h"
#include"run_py_script.h"
#include<string>

#include <cstdlib> // For system()
#pragma once


using namespace std;



int main(void)
{
	ask_usr user;
	data_handle data;
	Error_check check;
	IDW func;// calling the classes in the main function
	
	
	
	cout << "Welcome to the Inverse Distance Weighting (IDW) program." << endl;

	double power = user.get_power();
			
	int grid_x, grid_y;
	user.grid_check(grid_x, grid_y);


	int num_DH = user.get_num_DH();

	double** input_array = data.Create_DH_array(num_DH, grid_x, grid_y);

	input_array = check.all_check(grid_x, grid_y, input_array, num_DH);

	cout << "\n.............................................\n";
	func.IDW_top_func(grid_x, grid_y, power, input_array, num_DH); 
	cout << "\n.............................................\n";
	
	run_py();

	cout << "\n Complete, clearing data \n";
	for (int i = 0; i < num_DH; i++)
	{
		delete[] input_array[i];
	}
	delete[] input_array;

	cout << "\n succes \n";

}

