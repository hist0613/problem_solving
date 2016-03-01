#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class BootsExchange{
public:
	int leastAmount(vector <int> left, vector <int> right){
		vector<int> check(right.size());
		
		int ret = left.size();
		for(int i = 0; i < left.size(); i++){
			for(int j = 0; j < right.size(); j++){
				if(left[i] == right[j] && check[j] == 0){
					--ret;
					check[j] = 1;
					break;
				}
			}
		}
		
		return ret;
	}
};