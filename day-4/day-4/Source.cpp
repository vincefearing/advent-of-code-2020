#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "validation.h"
#include <vector>

using namespace std;

void part1();
void part2();


int main()
{
	part1();
	part2();
}

void part1()
{
	ifstream inFile;
	string temp;
	string check;
	validation validator;
	int valid = 0;

	inFile.open("data.txt");

	if (!inFile)
	{
		cout << "Problem opening file" << endl;
	}

	while (!inFile.eof())
	{
		getline(inFile, temp);
		if (temp != "")
		{
			for (int i = 0; i < temp.size(); ++i)
			{
				if (temp.at(i) == ':')
				{
					check = temp.substr(i - 3, 3);
					validator.validate(check);
					if (validator.isValid() == true)
					{
						valid++;
						validator.reset();
					}
				}
			}
		}
		else
		{
			validator.reset();
		}
	}


	cout << "Valid: " << valid << endl;
	inFile.close();
}

void part2()
{
	ifstream inFile;
	string temp;
	string check;
	validation validator;
	int valid = 0;

	inFile.open("data.txt");

	if (!inFile)
	{
		cout << "Problem opening file" << endl;
	}

	while (!inFile.eof())
	{
		getline(inFile, temp);
		if (temp != "")
		{
			for (int i = 0; temp.size() > 0; ++i)
			{
				if (temp.at(i) == ' ' || i == temp.size() - 1)
				{
					if (i == temp.size() - 1)
					{
						check = temp.substr(0, i + 1);
					}
					else
					{
						check = temp.substr(0, i);
					}
					validator.validate2(check);
					temp.erase(0, i+1);
					i = -1;
					if (validator.isValid() == true)
					{
						valid++;
						validator.reset();
					}
				}
			}
		}
		else
		{
			validator.reset();
		}
	}


	cout << "Valid: " << valid << endl;
	inFile.close();
}