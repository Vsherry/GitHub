#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool judgePassWordLength(string p_strFile);
bool judgeKindsOfPassWord(string p_strFile);
bool judgeIsRepeative(string p_strFile);

int main()
{
	string input;
	vector<string> result;
	while (cin>>input)
	{
		if (judgePassWordLength(input) && judgeIsRepeative(input) 
			&& judgeKindsOfPassWord(input)){
			result.push_back("OK");
		} 
		else{
			result.push_back("NG");
		}
	}
	for (vector<string>::iterator item = result.begin(); item != result.end();item++){
		cout << *item << endl;
	}
	return 0;
}

bool judgePassWordLength(string p_strFile)
{
	int sizeTemp = p_strFile.size();
	if (sizeTemp > 8){
		return true;
	}
	else{
		return false;
	}
}

bool judgeKindsOfPassWord(string p_strFile)
{
	int kinds = 0;
	vector<char> numberList;
	vector<char> letterList;
	vector<char> LETTERlist;
	vector<char> otherList;
	for (size_t i = 0; i < p_strFile.size();i++){
		char charTemp = p_strFile[i];
		if (charTemp >= 48 && charTemp <= 57){
			numberList.push_back(charTemp);
		}
		else{
			if (charTemp >= 65 && charTemp <= 90){
				LETTERlist.push_back(charTemp);
			}
			else{
				if (charTemp >= 96 && charTemp <= 122){
					letterList.push_back(charTemp);
				}
				else{
					otherList.push_back(charTemp);
				}
			}
		}
	}
	if (numberList.size() > 0){ kinds++; }
	if (LETTERlist.size() > 0){ kinds++; }
	if (letterList.size() > 0){ kinds++; }
	if (otherList.size() > 0){ kinds++; }

	if (kinds>=3){
		return true;
	}
	else{
		return false;
	}
}

bool judgeIsRepeative(string p_strFile)
{
	int result = 0;
	for (size_t i = 0; i < p_strFile.size() - 1;i++){
		string tempStr = p_strFile.substr(i, 3);
		string leftStr = p_strFile.substr(i + 3, p_strFile.size() - i - 3);
		size_t position = leftStr.find(tempStr);
		if (position!= string::npos){
			result++;
		}
	}
	if (result>0){
		return false;
	}
	else{
		return true;
	}
}
