#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class ReversingBrackets{
public:
	string removeBrackets(string s){
		if(s.find("[") == string::npos) return s;
		else{
			string ret = "";
			for(int i = 0; i < s.find("["); i++) ret += s[i];
			for(int i = s.find("]") - 1; i > s.find("["); i--) ret += s[i];
			for(int i = s.find("]") + 1; i < s.size(); i++) ret += s[i];
			return ret;
		}
	}
};