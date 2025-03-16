
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include"valid_num.h"
using namespace std;

class Error_check
{
public:
	double** valid_DH_values(double** DH, int num);
	double** repeat_DH_xy(double** DH, int& num);
	double** grid_greater_than_DH(int& max_x, int& max_y, double** DH, int num);

private:
	double** adjust_DH(double** DH, int& num, int i);
	double** adjust_grid(double** DH, int& max_x, int& max_y);

};


