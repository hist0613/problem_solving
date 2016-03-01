#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GroupWork{
public:
	long long bestGroup(vector <int> p, vector <int> s){
		vector<pair<long long, long long>> group(p.size());
		for(int i = 0; i < p.size(); i++) group[i] = make_pair(s[i], p[i]);
		
		sort(group.begin(), group.end());
		
		long long ret = 0;
		for(int i = 0; i < group.size(); i++){
			long long sum = 0;
			for(int j = i; j < group.size(); j++) sum += group[i].first * group[j].second;
			ret = max(ret, sum);
		}		
		
		return ret;
	}
};