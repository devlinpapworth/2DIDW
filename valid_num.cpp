#include"valid_num.h"

/*These functions are called repeatedly and take the users input as a string and checks each 'letter' of the string to see if it passed the respective test of integer or double*/

bool valid_double(string str)
{

	

	int count = 0;

	for (int i = 0; i < str.length(); i++) // loops through each char of string
	{
		if (!isdigit(str[i])) // if i is not a digit
		{
			if (str[i] == '.')
			{
				count++;
				if (count > 1) // allows only one decimal point
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

	return true; // if string is a digit
}


bool valid_int(string str)
{
	int count = 0;

	for (int i = 0; i < str.length(); i++) // loops through each char of string
	{
		if (!isdigit(str[i])) // if i is not a digit
		{

			return false;

		}
	}

	return true; // if string is a digit
}
