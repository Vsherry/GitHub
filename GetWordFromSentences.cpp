#include<iostream>
#include <istream>
#include <string>
#include <vector>
using namespace std;

vector<string> getWord(string worldList);

int main()
{
	string str;
	getline(cin, str);
	vector<string> stringlist = getWord(str);

	for (int i = 0; i < stringlist.size(); i++)
	{
		cout << stringlist[i] << endl;
	}

	return 0;
}

vector<string> getWord(string worldList)
{
	int index = 0;
	int numblank = 0;
	vector<string> stringlist;
	vector<int> numindex;
	while (index < worldList.size())
	{
		if (worldList[index] == ' ')
		{
			numblank++;
			numindex.push_back(index);
		}
		index++;
	}

	stringlist.push_back(worldList.substr(0, numindex[0]));
	for (int i = 0; i < numindex.size() - 1; i++)
	{
		stringlist.push_back(worldList.substr(numindex[i] + 1, numindex[i + 1] - numindex[i]));
	}
	stringlist.push_back(worldList.substr(numindex[numindex.size() - 1] + 1, worldList.size()));

	return stringlist;
}
