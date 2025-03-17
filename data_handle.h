
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "valid_num.h"

using namespace std;


class data_handle
{
public:
	double** Create_DH_array(int num_DH, int x, int y);
	
private: // self contained within class so only called in when user needs in the create dh array funcion
	
	void use_example_data(double** DH_array, int num_DH, int x, int y);
	void import_data_from_excel(double** DH_array, int num_DH);
	void manually_enter_data(double** DH_array, int num_DH);
	
	void count_rows(int num_DH, string filename);
};	