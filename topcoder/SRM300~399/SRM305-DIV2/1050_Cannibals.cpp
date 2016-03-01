#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Cannibals{
public:
	struct state{
		int mission; // remained missionaries
		int cannibal; // remained cannibals
		int side; // 0 is left(start), 1 is right
		state(int _m, int _c, int _s) : mission(_m), cannibal(_c), side(_s) {}
	};
	int cache[101][101][2]; // cache[i][j][k] = min count when i missionaries and j cannibals on k side

	int minCrossings(int M, int C, int R){
		memset(cache, -1, sizeof(cache));
		
		queue<state> q;
		q.push(state(0, 0, 0));
		cache[0][0][0] = 0;
		while(!q.empty()){
			int m = q.front().mission;
			int c = q.front().cannibal;
			int s = q.front().side;
			q.pop();
			
			for(int moveM = 0; moveM <= R; moveM++){
				for(int moveC = 0; moveM + moveC <= R; moveC++){
					if(moveM == 0 && moveC == 0) continue;
					
					// if s is 0, then m + moveM
					// else then m - moveM
					int remainM = m + (1 - 2 * s) * moveM;
					int remainC = c + (1 - 2 * s) * moveC;
					if(remainM < 0 || remainC < 0 || remainM > M || remainC > C) continue;
					if((remainM != 0 && remainM < remainC) || (M - remainM != 0 && M - remainM < C - remainC)) continue;
					
					if(cache[remainM][remainC][1-s] == -1){
						q.push(state(remainM, remainC, 1-s));
						cache[remainM][remainC][1-s] = cache[m][c][s] + 1;
					}
				}
			}
		}
		return cache[M][C][1];
	}
};