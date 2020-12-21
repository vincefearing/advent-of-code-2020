#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int valid = 0;
	
	ifstream inFile;
	char trash;
	int num1 = 0;
	int num2 = 0;
	char temp;
	string password;

	inFile.open("data.txt");

	if (!inFile)
	{
		cout << "Error opening file! " << endl;
	}

	while (!inFile.eof())
	{
		int count = 0;
		inFile >> num1 >> trash >> num2 >> temp >> trash >> password;

		for (int i = 0; i < password.size(); ++i)
		{
			if (password.at(i) == temp)
			{
				count++;
				//cout << count;
			}
		}
		if (count >= num1 && count <= num2)
		{
			valid++;
		}

	}
	cout << valid << endl;
	valid = 0;
	inFile.close();

	inFile.open("data.txt");

	while (!inFile.eof())
	{
		inFile >> num1 >> trash >> num2 >> temp >> trash >> password;

		num1--;
		num2--;

		if ((temp == password.at(num1)) ^ (temp == password.at(num2)))
		{
			valid++;
		}
	}

	cout << valid << endl;
}