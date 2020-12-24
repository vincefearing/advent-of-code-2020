#include <iostream>
#include <fstream>

using namespace std;

int treeCounter(int right, int down);

int main()
{
	/*unsigned product = treeCounter(1, 1) * treeCounter(3, 1) * treeCounter(5, 1) * treeCounter(7, 1) * treeCounter(1, 2);
	cout << product << endl;*/
	/*cout << treeCounter(1, 1) << endl;
	cout << treeCounter(3, 1) << endl;
	cout << treeCounter(5, 1) << endl;
	cout << treeCounter(7, 1) << endl;*/
	cout << treeCounter(1, 2) << endl;
}

int treeCounter(int right, int down)
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

	if (down == 2)
	{
		inFile >> temp;
		position = 1;
	}

	while (!inFile.eof())
	{
		//inFile >> temp;
		for (int i = 0; i < down; ++i)
		{
			inFile >> temp;
		}
		
		if (temp.at(position) == '#')
		{
			counter++;
		}

		position += right;

		if (position >= temp.size())
		{
			position = position - temp.size();
		}
	}

	return counter;
}