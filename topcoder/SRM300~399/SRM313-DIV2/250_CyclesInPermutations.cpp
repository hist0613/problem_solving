#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CyclesInPermutations{
public:
	int maxCycle(vector <int> board){
		int n = board.size();
		
		int ret = 0;
		for(int start = 0; start < n; start++){
			int curr = start, cnt = 0;
			do{
				++cnt;
				curr = board[curr] - 1;
			}while(curr != start);
			
			ret = max(ret, cnt);
		}
		
		return ret;
	}
};