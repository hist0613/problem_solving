#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class BifidSortMachine{
public:
	int countMoves(vector <int> a){
		int n = a.size();
		vector<int> sorted(a);
		sort(sorted.begin(), sorted.end());
		
		int ret = 987654321;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				bool flag = true;
				int prev = -987654321;
				for(int k = 0; k < n; k++){
					if(sorted[i] <= a[k] && a[k] <= sorted[j]){
						if(a[k] < prev){ flag = false; break; }
						prev = a[k];
					}
				}
				if(flag) ret = min(ret, n - (j - i + 1));
			}
		}
		return ret;
	}
};