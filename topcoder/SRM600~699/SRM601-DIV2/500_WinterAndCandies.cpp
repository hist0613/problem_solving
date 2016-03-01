#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class WinterAndCandies{
public:
	int getNumber(vector <int> type){
		int cnt[51] = {0};
		for(int i = 0; i < type.size(); i++) 
			cnt[type[i]]++;
				
		int p = 1, ret = 0;
		for(int i = 1; i <= 50; i++){
			p *= cnt[i];
			ret += p;
		}
		
		return ret;
	}
};