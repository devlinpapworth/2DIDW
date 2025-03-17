#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#pragma once
#include"valid_num.h"

using namespace std;

class ask_usr
{
public:
	int grid_check(int& grid_x, int& grid_y);
	double get_power();
	int get_num_DH();
private:
	int grid_size(int& grid_x, int& grid_y);
};


