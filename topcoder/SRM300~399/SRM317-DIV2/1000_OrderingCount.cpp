#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long countOrdering(int status);

int n;
long long cache[(1 << 20) + 1];
vector<string> req;

class OrderingCount{
public:
	long long countOrderings(vector <string> require){
		n = require.size();
		req = require;
		memset(cache, -1, sizeof(cache));
		cache[(1<<n)-1] = 1;
		for(int i = 0; i < n; i++) if(req[i][i] == 'Y') return 0;
		return countOrdering(0);
	}
};
long long countOrdering(int status){
	long long &ret = cache[status];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < n; i++){
		if(status & (1 << i)) continue; 
		bool flag = true;
		for(int j = 0; j < n; j++){
			if((status & (1 << j)) && req[i][j] == 'Y'){
				flag = false;
				break;
			}
		}
		if(flag) ret += countOrdering(status | 1 << i);
	}
	return ret;
}