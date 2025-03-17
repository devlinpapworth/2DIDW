#include "ask_usr.h"



double ask_usr::get_power()
{

	string temp;
	cout << "The power in the IDW formula controls the influence of distance. Increasing the power gives more weight to nearby points,"<<
		 " making the interpolation sharper." << endl;

	do
	{
		cout << "Enter Power value (Recomended between 1-2):" << endl;
		cin >> temp;

		if (valid_double(temp) && stod(temp) > 0)// if number is valid then break
		{
			break;
		}
		cout << "Oops, looks like that entry didn't work. Try again: ";


	} while (true);

	double power = stod(temp);


	return(power);
}


int ask_usr::get_num_DH()
{
	string temp;
	do {
		cout << "How many Drill Holes do you want to enter? " << endl;
		cin >> temp;
		if (valid_int(temp) && stoi(temp) > 0)
		{
			break;

		}
		cout << "Oops, looks like that entry didn't work. Try again: ";
	} while (true);

	return(stoi(temp));
}


int ask_usr::grid_check(int& grid_x, int& grid_y)
{
	do
	{
		grid_size(grid_x, grid_y);
		char Y_N;
		cout << "Your grid dimensions are " << grid_x << "x by " << grid_y << "y" << endl;

		cout << "Is this correct (y/n)?: " << endl;
		cin >> Y_N;

		if (Y_N == 'y' || Y_N == 'Y')
		{
			cout << "\nAmazing! Let's start.\n" << endl;
			break;
		}

		cout << "Oh no, let's try again." << endl;


	} while (true);
	return(0);
}



int ask_usr::grid_size(int& grid_x, int& grid_y) // taking in where the memory of grid x,y is stored and editing it in the member function
{

	// ask user to define the size of the output grid

	cout << "Enter the dimensions of your output block model grid. " << endl;
	string temp_x;
	do
	{
		cout << "X value: " << endl;
		cin >> temp_x;

		if (valid_int(temp_x) && stoi(temp_x) > 0)// if number is valid then break
		{
			break;
		}
		cout << "Oops, looks like that entry didn't work. Try again: ";


	} while (true);

	grid_x = stoi(temp_x);


	string temp_y;
	do
	{
		cout << "Y value: " << endl;
		cin >> temp_y;

		if (valid_int(temp_y) && stoi(temp_y) > 0)// if number is valid then break
		{
			break;
		}
		cout << "Oops, looks like that entry didn't work. Try again: ";


	} while (true);

	grid_y = stoi(temp_y);


	return(0);
}

