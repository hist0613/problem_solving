#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class ParallelProgramming{
public:
	int minTime(vector <int> time, vector <string> prec){
		int n = time.size();
		
		queue<int> q;
		vector<int> total(n);
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = 0; j < n; j++)
				if(prec[i][j] == 'Y') ++cnt;
			
			if(cnt == 0){
				q.push(i);
				total[i] = time[i];
			}
		}
		
		while(!q.empty()){
			int curr = q.front(); q.pop();
			
			for(int i = 0; i < n; i++){
				if(prec[i][curr] == 'Y'){
					prec[i][curr] = 'N';
					int cnt = 0;
					for(int j = 0; j < n; j++)
						if(prec[i][j] == 'Y') ++cnt;
					
					total[i] = max(total[i], total[curr] + time[i]);
					if(cnt == 0) q.push(i);
				}
			}
		}
		
		int ret = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				if(prec[i][j] == 'Y') return -1;
			ret = max(ret, total[i]);
		}
		
		return ret;		
	}
};