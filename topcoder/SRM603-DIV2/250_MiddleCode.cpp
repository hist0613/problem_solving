#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MiddleCode{
public:
	string encode(string s){
		string t = "";
		while(!s.empty()){
			int mp = s.size() / 2;
			if(s.size() % 2 == 0 && s[s.size() / 2 - 1] < s[s.size() / 2]) mp--;
			t += s[mp];
			s.erase(s.begin() + mp);
		}
		return t;
	}
};