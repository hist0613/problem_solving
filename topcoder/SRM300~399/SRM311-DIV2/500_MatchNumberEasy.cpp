#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string cache[51];

class MatchNumbersEasy{
public:
	string maxNumber(vector <int> matches, int n){
		for(int i = 0; i < matches.size(); i++) cache[matches[i]] = '0' + i;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j * 2 <= i; j++){
				string temp = cache[j] + cache[i-j];
				sort(temp.rbegin(), temp.rend());
				if(temp.size() > cache[i].size() && temp[0] != '0') cache[i] = temp;
				else if(temp.size() == cache[i].size() && temp > cache[i]) cache[i] = temp;
			}
		}
		
		string ret = cache[n];
		if(count(ret.begin(), ret.end(), '0') == ret.size()) return "0";
		else return ret;
	}
};