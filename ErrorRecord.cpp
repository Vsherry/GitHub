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

class ErrorRecord
{
public:
	string m_fileName;
	int m_channelNum;
	int repeatNum;

	ErrorRecord() :m_fileName(""), m_channelNum(0),repeatNum(1){

	}
	bool operator==(ErrorRecord p_item){
		if (p_item.m_fileName==this->m_fileName&&p_item.m_channelNum==this->m_channelNum){
			return true;
		}
		else{
			return false;
		}
	}
	ErrorRecord operator=(ErrorRecord p_item){
		this->m_channelNum = p_item.m_channelNum;
		this->m_fileName = p_item.m_fileName;
		this->repeatNum = p_item.repeatNum;
		return *this;
	}
};

string getFileName(string p_strFile);

int main()
{
	int channelNum;
	string input;
	vector<ErrorRecord> resultVec;
	while (cin >> input>>channelNum)
	{
		ErrorRecord item;
		item.m_channelNum = channelNum;
		item.m_fileName = getFileName(input);
		//resultVec.push_back(item);

		int tempSize = resultVec.size();
		int index = -1;
		for (size_t i = 0; i < tempSize; i++){
			if (item == resultVec[i]){
				index = i;
			}
		}
		if (index == -1){
			resultVec.push_back(item);
		}
		else{
			resultVec[index].repeatNum++;
		}
	}
	int nicai = resultVec.size();
	if (nicai>8){
		for (int i = nicai - 8; i < nicai; i++){
			cout << resultVec[i].m_fileName << " " << resultVec[i].m_channelNum << " " << resultVec[i].repeatNum << endl;
		}
	} 
	else{
		for (int i = 0; i < resultVec.size(); i++){
			cout << resultVec[i].m_fileName << " " << resultVec[i].m_channelNum << " " << resultVec[i].repeatNum << endl;
		}
	}
	
	return 0;
}


string getFileName(string p_strFile)
{
	string fileName = p_strFile;
	int index = fileName.find_last_of('\\');
	if (index < fileName.size()-1){
		fileName = fileName.substr(index + 1, fileName.size() - index - 1);
	}
	if (fileName.size()>16){
		fileName = fileName.substr(fileName.size() - 16, 16);
	}
	return fileName;
}
