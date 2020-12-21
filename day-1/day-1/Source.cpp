#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream inFile;
	vector <int> list;
	int result1 = 0;
	int result2 = 0;
	int temp = 0;

	inFile.open("Text.txt");

	if (!inFile)
	{
		cout << "Problem opening file";
	}

	while (!inFile.eof())
	{
		inFile >> temp;  
		list.push_back(temp);
	}

	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = 0; j < list.size(); ++j)
		{
			temp = list.at(i) + list.at(j);
			if (temp == 2020)
			{
				result1 = list.at(i) * list.at(j);
			}
		}
	}

	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = 0; j < list.size(); ++j)
		{
			for (int k = 0; k < list.size(); ++k)
			{
				temp = list.at(i) + list.at(j) + list.at(k);
				if (temp == 2020)
				{
					result2 = list.at(i) * list.at(j) * list.at(k);
				}
			}
		}
	}

	cout << "Result1: " << result1;
	cout << "Result2: " << result2;
}