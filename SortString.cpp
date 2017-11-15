#include <iostream> 
#include <cstdio> 
#include <vector> 
#include <cmath> 
#include <cstring> 
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<string> getWord(string worldList);
string reverse(string sentence);
vector<string> sortString(vector<string> p_input);

int main()
{
	int number = 0;
	vector<string> strVec;
	vector<string> result;
	cin >> number;
	while (number>0)
	{
		string input;
		cin >> input;
		strVec.push_back(input);
		number--;
	}
	result = sortString(strVec);
	for (size_t i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}

vector<string> sortString(vector<string> p_input)
{
	sort(p_input.begin(), p_input.end(), [](string a, string b){return a < b; });
	return p_input;
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
		stringlist.push_back(worldList.substr(numindex[i] + 1, numindex[i + 1] - numindex[i]-1));
	}
	stringlist.push_back(worldList.substr(numindex[numindex.size() - 1] + 1, worldList.size()));

	return stringlist;
}

string reverse(string sentence)
{
	vector<string> stringlist = getWord(sentence);
	string result;
	for (int i = stringlist.size() - 1; i >= 0; i--)
	{
		result+=stringlist[i];
		result += " ";
	}
	result =result.substr(0,result.size()-1);
	return result;
}




