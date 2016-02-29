#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CreatePairs{
public:
	int maximalSum(vector<int> data){
		vector<int> minus, plus;
		int one = 0;
		int zero = 0;
		
		for(int i = 0; i < data.size(); i++){
			if(data[i] < 0) minus.push_back(data[i]);
			else if(data[i] > 1) plus.push_back(data[i]);
			else if(data[i] == 1) one++;
			else zero++;
		}
		
		sort(minus.begin(), minus.end());
		sort(plus.rbegin(), plus.rend());
		
		int ret = 0;
		for(int i = 1; i < plus.size(); i+=2)
			ret += plus[i] * plus[i - 1];
		for(int i = 1; i < minus.size(); i+=2)
			ret += minus[i] * minus[i - 1];
		if(minus.size() % 2 == 1 && zero == 0)
			ret += minus[minus.size() - 1];
		if(plus.size() % 2 == 1)
			ret += plus[plus.size() - 1];
		ret += one;
		
		return ret;
	}
};
