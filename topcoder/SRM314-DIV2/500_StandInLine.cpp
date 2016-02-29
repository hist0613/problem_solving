#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class StandInLine{
public:
	vector <int> reconstruct(vector <int> _left){
		vector<pair<int, int>> left;
		for(int i = 0; i < _left.size(); i++)
			left.push_back(make_pair(_left[i], i + 1));
		
		sort(left.begin(), left.end(), [](const pair<int, int> &i, const pair<int, int> &j){
			if(i.first == j.first) return i.second > j.second;
			return i.first < j.first;
		});
		
		vector<int> result;
		for(int i = 0; i < left.size(); i++){
			int idx = 0, taller = 0;
			while(idx < result.size() && taller < left[i].first){
				if(result[idx] > left[i].second) ++taller;
				++idx;
			}
			result.emplace(result.begin() + idx, left[i].second);
		}
		
		return result;
	}
};