#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string check(long long small, long long large, long long number){
	for(long long pow = 1; number * pow <= large; pow *= 10)
		if(small / pow <= number && number <= large / pow) return "VALID";
	return "INVALID";
}

class InputBoxChecker{
public:
	vector <string> checkPrefix(int smallest, int largest, vector <int> numbers){
		vector<string> ret(numbers.size());
		
		for(int i = 0; i < numbers.size(); i++)
			ret[i] = check(smallest, largest, numbers[i]);
		return ret;
	}
};