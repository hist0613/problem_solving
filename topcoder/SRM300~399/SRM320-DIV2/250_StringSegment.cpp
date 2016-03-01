#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class StringSegment{
public:
	double average(string s){
		int sum = 0, cnt = 0;
		s += ' ';
		string temp = s.substr(0, 1);
		for(int i = 1; i < s.size(); i++){
			if(s[i] != s[i-1]){
				sum += temp.size();
				++cnt;
				temp = "";
			}
			temp += s[i];
		}
		return (double)sum / cnt;
	}
};