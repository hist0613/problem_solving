#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class TaroGrid{
public:
	int getNumber(vector <string> grid){
		int n = grid.size();
		int ret = 1;
		for(int col = 0; col < n; col++){
			int cnt = 1;
			for(int row = 1; row < n; row++){
				if(grid[row][col] == grid[row - 1][col]){
					++cnt;
					ret = max(ret, cnt);
				}
				else cnt = 1;
			}
		}
		return ret;
	}
};