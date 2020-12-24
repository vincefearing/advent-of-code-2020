#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "validation.h"
#include <vector>

using namespace std;


int main()
{
	ifstream inFile;
	string temp;
	string check;
	validation validator;
	int valid = 0;
	//queue <string> passport;
	vector <string> passport;

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
}