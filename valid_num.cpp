#include"valid_num.h"

bool valid_double(string str)
{
	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) // if i is not a digit
		{
			if (str[i] == '.')
			{
				count++;
				if (count > 1) // if more than one decimal place = error
				{
					return false;
				}

			}

			else
			{
				return false; // if string is not a digit
			}
		}
	}

	return true;
}


bool valid_int(string str)
{
	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) // if i is not a digit
		{

			return false;

		}
	}

	return true;
}
