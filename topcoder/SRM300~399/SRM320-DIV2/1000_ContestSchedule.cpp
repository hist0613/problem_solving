#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Contest{
	int s, t, p;
};
class ContestSchedule{
public:
	double expectedWinnings(vector <string> param){
		int n = param.size();
		vector<Contest> contests(n);
		for(int i = 0; i < n; i++){
			stringstream ssin(param[i]);
			ssin>>contests[i].s>>contests[i].t>>contests[i].p;
		}
		
		sort(contests.begin(), contests.end(), [](const Contest &i, const Contest &j){
			if(i.t == j.t) return i.s < j.s;
			else return i.t < j.t;
		});
		
		int ret = 0;
		vector<int> cache(n);
		for(int i = 0; i < n; i++){
			cache[i] = contests[i].p;
			for(int j = 0; j < i; j++){
				if(contests[j].t <= contests[i].s && cache[j] + contests[i].p > cache[i]){
					cache[i] = cache[j] + contests[i].p;
				}
			}
			ret = max(ret, cache[i]);
		}
		return (double) ret / 100.0;
	}
};