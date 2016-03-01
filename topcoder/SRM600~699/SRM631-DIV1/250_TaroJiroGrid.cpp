#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class TaroJiroGrid{
public:
	bool isGood(vector <string> grid){
		int n = grid.size();
		for(int col = 0; col < n; col++){
			int max_cnt = 1;
			int cnt = 1;
			for(int row = 1; row < n; row++){
				if(grid[row][col] == grid[row - 1][col]){
					++cnt;
					max_cnt = max(max_cnt, cnt);
				}
				else cnt = 1;
			}
			if(max_cnt > n / 2) return false;
		}
		return true;
	}
	int getNumber(vector <string> grid){
		int n = grid.size();
		if(isGood(grid)) return 0;
		for(int row = 0; row < n; row++){
			vector<string> temp = grid;
			for(int c = 0; c <= 1; c++){
				for(int col = 0; col < n; col++) temp[row][col] = (c == 0 ? 'W' : 'B');
				if(isGood(temp)) return 1;				
			}
		}
		return 2;
	}
};