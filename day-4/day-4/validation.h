#pragma once
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class validation
{
private:
	bool ecl;
	bool pid;
	bool eyr;
	bool hcl;
	bool byr;
	bool iyr;
	bool cid;
	bool hgt;
public:
	void reset();
	validation();
	void validate(string temp);
	void validate2(string temp);
	bool isValid();
};