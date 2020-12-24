#include "validation.h"

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