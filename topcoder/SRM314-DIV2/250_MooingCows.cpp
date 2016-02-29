#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int square(int x){
	return x * x;
}

class MooingCows{
public:
	int dissatisfaction(vector <string> farmland){
		int n = farmland.size(), m = farmland[0].size();
		
		vector<pair<int, int> > cows;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(farmland[i][j] == 'C') cows.push_back(make_pair(i, j));
		
		int ret = 987654321;
		for(int i = 0; i < cows.size(); i++){
			int sum = 0;
			for(int j = 0; j < cows.size(); j++) 
				sum += square(cows[i].first - cows[j].first) + square(cows[i].second - cows[j].second);
			
			ret = min(sum, ret);
		}
		
		return ret;				
		
	}
};