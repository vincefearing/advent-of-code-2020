#include "validation.h"
#include <ctype.h>

validation::validation()
{
	ecl = false;
	pid = false;
	eyr = false;
	hcl = false;
	byr = false;
	iyr = false;
	cid = false;
	hgt = false;
}

void validation::validate(string temp)
{
	string sub = temp;
	//string sub;
	
	//sub = temp.substr(0, 3);
	if (sub == "ecl")
	{
		ecl = true;
	}
	else if (sub == "pid")
	{
		pid = true;
	}
	else if (sub == "eyr")
	{
		eyr = true;
	}
	else if (sub == "hcl")
	{
		hcl = true;
	}
	else if (sub == "byr")
	{
		byr = true;
	}
	else if (sub == "iyr")
	{
		iyr = true;
	}
	else if (sub == "cid")
	{
		cid = true;
	}
	else if (sub == "hgt")
	{
		hgt = true;
	}
		
}

void validation::validate2(string temp)
{
	string field = temp.substr(0, 3);
	string value = temp.substr(4, temp.size() - 3);
	if (field == "ecl")
	{
		if (value == "amb" || value == "blu" || value == "gry" || value == "grn" || value == "hzl" || value == "oth" || value == "brn")
		{

			ecl = true;
		}
	}
	else if (field == "pid")
	{
		bool isNumber = false;
		for (int i = 0; i < value.size(); ++i)
		{
			if (isdigit(value.at(i)))
			{
				isNumber = true;
			}
		}
		if (value.size() == 9 && isNumber == true)
		{
			pid = true;
		}
	}
	else if (field == "eyr")
	{
		int numValue = stoi(value);
		if (numValue >= 2020 && numValue <= 2030)
		{
			eyr = true;
		}
	}
	else if (field == "hcl")
	{
		string sub = value.substr(0, 7);
		bool valid = false;
		if (value.at(0) == '#')
		{
			for (int i = 1; i < sub.size(); ++i)
			{
				if (sub.at(i) >= '0' && sub.at(i) <= '9')
				{
					valid = true;
				}
				else if (sub.at(i) >= 'a' && sub.at(i) <= 'f')
				{
					valid = true;
				}
				else
				{
					valid = false;
				}
			}
		}
		
		if (sub.size() == 7 && valid == true)
		{
			hcl = true;
		}
	}
	else if (field == "byr")
	{
		int numValue = stoi(value);
		if (value.size() == 4 && numValue >= 1920 && numValue <= 2002)
		{
			byr = true;
		}
	}
	else if (field == "iyr")
	{
		int numValue = stoi(value);
		if (value.size() == 4 && numValue >= 2010 && numValue <= 2020)
		{
			iyr = true;
		}
	}
	else if (field == "cid")
	{
		cid = true;
	}
	else if (field == "hgt")
	{
		string num = "";
		string unit = "";
		bool flag = false;
		for (int i = 0; i < value.size(); ++i)
		{
			if (isdigit(value.at(i)) && flag == false)
			{
				num = num + value.at(i);
			}
			else if (isalpha(value.at(i)))
			{
				flag = true;
				unit = unit + value.at(i);
			}
		}

		int numValue = stoi(num);
		if (unit == "cm")
		{
			if (numValue >= 150 && numValue <= 193)
			{
				hgt = true;
			}
		}
		else if (unit == "in")
		{
			if (numValue >= 59 && numValue <= 76)
			{
				hgt = true;
			}
		}
		else
		{
			cout << value << endl;
		}
	}
}
	

bool validation::isValid()
{
	if (ecl == true && pid == true && eyr == true && hcl == true && byr == true && iyr == true && hgt == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void validation::reset()
{
	ecl = false;
	pid = false;
	eyr = false;
	hcl = false;
	byr = false;
	iyr = false;
	cid = false;
	hgt = false;
}