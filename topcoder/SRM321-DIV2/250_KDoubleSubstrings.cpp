#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isKDouble(string str, int k){
	int cnt = 0, half = str.size() / 2;
	for(int i = 0; i < half; i++){
		if(str[i] != str[half + i]) ++cnt;
	}
	if(cnt <= k) return true;
	else return false;
}

class KDoubleSubstrings{
public:
	int howMuch(vector <string> list, int k){
		string str = "";
		for(int i = 0; i < list.size(); i++) str += list[i];
		
		int n = str.size();
		int ret = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(((j - i + 1) & 1) == 0 && isKDouble(str.substr(i, j - i + 1), k)) ++ret;
			}
		}
		return ret;
	}
};