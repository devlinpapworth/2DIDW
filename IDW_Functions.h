
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip> // for 2 decimal places

using namespace std;


class IDW
{
	const double deci = 1e-6;

	double top, bottom;

	public:
		double IDW_top_func(double usr_grid_x, double usr_grid_y, double pow, double** input_array, int num_DH);
		
	private: // these member functions only run within IDW top func
		double prog_perc(double x, double y, double num, double i);
		double run_IDW_for_one_block(double target_x, double target_y, double Pow, double** input_array, int num_DH);
};


