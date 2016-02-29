#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class HiddenMessage{
public:
	string getMessage(string text){
		stringstream ss(text);
		string ret = "", temp;
		while(ss>>temp) ret += temp[0];
		return ret;
	}
};