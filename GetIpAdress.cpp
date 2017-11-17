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

vector<int> getWord(string worldList);
int judgeIp(vector<int> p_ipVec);

int main()
{
	string input;
	vector<int> ipAdress;
	vector<int> result(7, 0);
	while (cin >> input)
	{
		ipAdress = getWord(input);
		int resultTemp = judgeIp(ipAdress);

		if (resultTemp == 0){ result[0]++; }
		if (resultTemp == 1){ result[1]++; }
		if (resultTemp == 2){ result[2]++; }
		if (resultTemp == 3){ result[3]++; }
		if (resultTemp == 4){ result[4]++; }
		if (resultTemp == 5){ result[5]++; }
		if (resultTemp == 60){ result[6]++; result[0]++; }
		if (resultTemp == 61){ result[6]++; result[1]++; }
		if (resultTemp == 62){ result[6]++; result[2]++; }
	}

	for (int i = 0; i < 6; i++){
		cout << result[i] << " ";
	}
	cout << result[6];
	return 0;
}

vector<int> getWord(string worldList)
{
	int index = 0;
	int numblank = 0;
	int ipFlag = 0;
	vector<string> stringlist;
	vector<int> numindex;
	vector<int> result;
	while (index < worldList.size())
	{
		if (worldList[index] == '.' || worldList[index] == '~'){
			numblank++;
			numindex.push_back(index);
		}
		index++;
	}
	stringlist.push_back(worldList.substr(0, numindex[0]));
	for (int i = 0; i < numindex.size() - 1; i++){
		if (numindex[i] + 1 != numindex[i + 1]){
			stringlist.push_back(worldList.substr(numindex[i] + 1, numindex[i + 1] - numindex[i] - 1));
		}
	}
	if (numindex[numindex.size() - 1] != worldList.size() - 1){
		stringlist.push_back(worldList.substr(numindex[numindex.size() - 1] + 1, worldList.size() - numindex[numindex.size() - 1]));
	}
	for (size_t i = 0; i < stringlist.size(); i++){
		int tempInt = 0;
		stringstream ssTemp(stringlist[i]);
		ssTemp >> tempInt;
		result.push_back(tempInt);
	}
	return result;
}

int judgeIp(vector<int> p_ipVec)
{
	int result = 99999;
	int vecSize = p_ipVec.size();
	bool subIsRight = false;
	bool isAbove255 = true;
	vector<int> zeroIndex;
	if (vecSize != 8){
		result = 5;
	}
	else{
//------------------判断掩码是否正确-----------------
		for (int i = 4; i < 8; i++){
			if (p_ipVec[i] == 0 || p_ipVec[i] == 128 || p_ipVec[i] == 192 || p_ipVec[i] == 224 ||
				p_ipVec[i] == 240 || p_ipVec[i] == 248 || p_ipVec[i] == 252 || p_ipVec[i] == 254){
				int temp = 0;
				for (int j = i+1; j < 8; j++){
					temp += p_ipVec[j];
				}
				if (temp > 0){
					result = 5;
					break;
				}
				else{
					subIsRight = true;
				}
			}
			else{
				if (p_ipVec[i] != 255){
					result = 5;
					break;
				}
			}
		}
//----------------判断IP类型-------------------
		if (result != 5){
			for (int k = 0; k < 4; k++){
				if (p_ipVec[k] > 255 || p_ipVec[k] < 0){
					isAbove255 = false;
				}
			}
			if (subIsRight&&isAbove255){
				int ipStart = p_ipVec[0];
				int subStart = p_ipVec[4];
				if (ipStart > 0 && ipStart < 127){
					if (ipStart == 10){
						result = 60;
					}
					else{
						result = 0;
					}
				}
				if (ipStart > 127 && ipStart < 192){
					if (ipStart == 172 && p_ipVec[1]>15 && p_ipVec[1] < 32){
						result = 61;
					}
					else{
						result = 1;
					}
				}
				if (ipStart > 191 && ipStart < 224){
					if (ipStart == 192 && p_ipVec[1] == 168){
						result = 62;
					}
					else{
						result = 2;
					}
				}
				if (ipStart > 223 && ipStart < 240){
					result = 3;
				}
				if (ipStart > 239 && ipStart < 256){
					result = 4;
				}
			}
			else{
				result = 5;
			}
		}
	}
	return result;
}