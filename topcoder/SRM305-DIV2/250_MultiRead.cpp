#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MultiRead{
public:
	int minCycles(string trace, int procs){
		int ret = 0, use = 0;
		for(int i = 0; i < trace.size(); i++){
			if(trace[i] == 'W'){
				++ret;
				use = 0;
			}
			else{
				if(use == 0) ++ret;
				use = (use + 1) % procs;
			}
		}
		return ret;
	}
};