#include "ask_usr.h"




int ask_usr::grid_size(int& grid_x, int& grid_y) // taking in where the memory of grid x,y is stored and editing it in the member function
{
	
	// ask user to define the size of the output grid
	
		cout << "Enter the Dimensions of your ouutput block model grid." << endl;
		string temp_x;
		do
		{
			cout << "X value:" << endl;
			cin >> temp_x;

			if (valid_int(temp_x) && stoi(temp_x) > 0)// if number is valid then break
			{
				break;
			}
			cout << "Oops, looks like that entry didnt work. Try again: ";


		} while (true);

		grid_x = stoi(temp_x);


		string temp_y;
		do
		{
			cout << "Y value:" << endl;
			cin >> temp_y;

			if (valid_int(temp_y) && stoi(temp_y) > 0)// if number is valid then break
			{
				break;
			}
			cout << "Oops, looks like that entry didnt work. Try again: ";


		} while (true);

		grid_y = stoi(temp_y);


	return(0);
}


double ask_usr::get_power()
{

	string temp;
	cout << "The power in the IDW formula controls the influence of distance. A Power value closer to 1 alows" <<
		" for a more gradual and smooth output, where a higher value weights distance more signficantly and therefor a sharper output." << endl;

	do
	{
		cout << "Enter Power value (Recomended between 1-2):" << endl;
		cin >> temp;

		if (valid_double(temp) && stod(temp) > 0)// if number is valid then break
		{
			break;
		}
		cout << "Oops, looks like that entry didnt work. Try again: ";


	} while (true);

	double power = stod(temp);


	return(power);
}


double
string temp;
do {
	cout << "How many Drill holes do you want to enter? " << endl;
	cin >> temp;
	if (valid_int(temp) && stod(temp) > 0)
	{
		break;

	}
	cout << "Oops, looks like that entry didnt work. Try again: ";
} while (true);


