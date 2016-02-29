#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PalindromeDecoding{
public:
	string decode(string code, vector <int> position, vector <int> length){
		for(int i = 0; i < position.size(); i++){
			string temp = code.substr(position[i], length[i]);
			temp = string(temp.rbegin(), temp.rend());
			code = code.substr(0, position[i] + length[i]) + temp + code.substr(position[i] + length[i]);
		}
		return code;
	}
};