#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class SpreadingNews{
public:
	int minTime(vector <int> supervisors){
		vector<int> max_time(supervisors.size());
		for(int i = supervisors.size() - 1; i >= 0; i--){
			vector<int> child;
			for(int j = i + 1; j < supervisors.size(); j++)
				if(supervisors[j] == i) child.push_back(max_time[j]);
			sort(child.rbegin(), child.rend());
			for(int j = 0; j < child.size(); j++){
				max_time[i] = max(max_time[i], child[j] + j + 1);				
			}
		}
		return max_time[0];
	}
};