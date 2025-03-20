
#include "IDW_Functions.h"

fstream myFile;


double IDW::IDW_top_func(double usr_grid_x, double usr_grid_y, double pow, double** input_array, int num_DH)
{
	
	double count = 0;
	ofstream outFile("IDW_output.csv"); // Open file for writing

	if (!outFile) 
	{
		cerr << "Error: Could not open output file!" << endl;
	}

	for (int j = 1; j <= usr_grid_y; j++) // loops through the grid y co-ords
	{

		for (int i = 1; i <= usr_grid_x; i++) // loops through the grid x co-ords
		{
			top = 0; //reseting the IDW formula values
			bottom = 0;

			count = prog_perc(usr_grid_x, usr_grid_y, num_DH, count);

			double val = run_IDW_for_one_block(i, j, pow, input_array, num_DH);

			outFile << fixed << setprecision(4) << val; // writes the value to the output file with two decimal places
			if (i < usr_grid_x)
			{
				outFile << ","; // if not at the end of the row then add a comma
			}
		}

		outFile << "\n"; // if at the end of the row then add a new line
	}

	return(0);
}




double IDW::run_IDW_for_one_block(double target_x, double target_y, double Pow, double** input_array, int num_DH)
{
	double x, y, t_val, s_val;
	bool valid = 0;

	for (int i = 0; i < num_DH; i++) // test all the drill holes to make sure that the grid target square being searched is not already a sample sqaure.
	{
		x = input_array[i][0];
		y = input_array[i][1];
		t_val = input_array[i][2];

		if ((fabs(target_x - x) > deci) || (fabs(target_y - y) > deci))
		{
			/*if the target square x and y are both different then valid = 1 allowing the IDW to run. 
			If they are both the same then there is already data in that square so dont need to run the IDW*/
			valid = 1;
		}
		else // if that IDW cannot run then break this loop
		{
			valid = 0; // sets valid back to 0 so IDW cannot run
			break;
		}

	}



	for (int i = 0; i < num_DH; i++) // loops througuh all the drill holes for one target grid square
	{

		if (valid == 1) // works out distance when there is a valid grade value and when it is not the same square
		{
			x = input_array[i][0];
			y = input_array[i][1];
			t_val = input_array[i][2];
			/*This Function works out the distance from the target(x,y) block square to one known value grid square*/


			// pythag to work out distance to DH co-ords from the target square
			double temp = pow(target_x - x, 2) + pow(target_y - y, 2);
			double sqrt_distance = sqrt(temp);

			/*sums the result of the target to sample(n) part of IDW formula to the top value and bottom value*/
			top = top + (t_val / (pow(sqrt_distance, Pow)));

			bottom = bottom + (1.0 / pow(sqrt_distance, Pow));

		}

	}


	if (valid == 1) // if the target square is not the same as the drill hole square then run the IDW formula
	{
		s_val = (top / bottom);
	}
	else // if the target square is the same as the drill hole square then just use the drill hole value already their
	{

		s_val = t_val;

	}


	return (s_val);
}


double IDW::prog_perc(double x, double y, double num, double i)
{
	
	double progress = (i / (x * y)) * 100;

	cout << "\rProgress: " << trunc(progress + 0.5) << "%" << flush;
	// rewrites over the line updating with the current percentage complete


	return(i + 1);
}

