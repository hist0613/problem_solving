#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, long long> parse_string(string str){
	long long val = 0;
	int fact = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] != '!') val = val * 10 + (str[i] - '0');
		else ++fact;
	}
	while(fact && val <= 12){
		long long temp = 1;
		for(int i = 1; i <= val; i++) temp *= i;
		val = temp;
		--fact;
	}
	
	return make_pair(fact, val);
}
class ExtraordinarilyLarge{
public:
	string compare(string _x, string _y){
		pair<int, long long> x = parse_string(_x);
		pair<int, long long> y = parse_string(_y);
		
		if(x < y) return "x<y";
		else if(x > y) return "x>y";
		else return "x=y";
	}
};