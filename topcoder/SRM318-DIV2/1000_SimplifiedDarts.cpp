#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

double getCache(int turn, int score);
double cache[1001][1001];

class SimplifiedDarts{
public:
	double tryToWin(int W, int N, int P1, int P2){
		double p1 = (double)P1 / 100.0;
		double p2 = (double)P2 / 100.0;
		for(int turn = 1; turn <= N; turn++){
			cache[turn][0] = 1.0;
			for(int score = 1; score <= W; score++){
				cache[turn][score] = max(p1 * getCache(turn - 1, score - 2) +  (1 - p1) * getCache(turn - 1, score),
										p2 * getCache(turn - 1, score - 3) + (1 - p2) * getCache(turn - 1, score));
			}
		}
		return cache[N][W] * 100;
	}
};
double getCache(int turn, int score){
	if(score <= 0) return 1.0;
	if(turn <= 0) return 0;
	return cache[turn][score];
}