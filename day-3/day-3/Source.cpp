#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("data.txt");
	int counter = 0;
	int position = 0;
	string temp;

	if (!inFile)
	{
		cout << "Error opening file" << endl;
	}

	while (!inFile.eof())
	{
		inFile >> temp;
		if (temp.at(position) == '#')
		{
			counter++;
		}

		position += 3;

		if (position >= temp.size())
		{
			position = position - temp.size();
		}
	}

	cout << "Trees: " << counter << endl;
}