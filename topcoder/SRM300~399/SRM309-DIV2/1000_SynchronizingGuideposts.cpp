#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n;

long long calculate(vector<long long> &position, vector<long long> &limit, long long gas_station, long long C){
	long long total_cost = 0;
	for(int i = 0; i < n; i++){
		long long distance = abs(gas_station - position[i]);
		total_cost += distance;
		if(distance > limit[i]) total_cost += C * (distance - limit[i]);
	}
	return total_cost;
}

class SynchronizingGuideposts{
public:
	long long minCost(vector <string> guideposts, int C){
		vector<long long> position;
		vector<long long> limit;
		n = guideposts.size();
		for(int i = 0; i < n; i++){
			stringstream ss(guideposts[i]);
			long long pos, dis, lim;
			ss>>pos>>dis>>lim;
			position.push_back(pos + dis);
			limit.push_back(lim);
		}
		
		long long ret = calculate(position, limit, 0, C);
		for(int i = 0; i < n; i++){
			if(position[i] > 0) ret = min(ret, calculate(position, limit, position[i], C));
			if(position[i] - limit[i] > 0) ret = min(ret, calculate(position, limit, position[i] - limit[i], C));
			if(position[i] + limit[i] > 0) ret = min(ret, calculate(position, limit, position[i] + limit[i], C));
		}
		
		return ret;
	}
};