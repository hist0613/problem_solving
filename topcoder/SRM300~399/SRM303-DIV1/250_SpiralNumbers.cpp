#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ret(int x, int y){
	return "(" + to_string(x)+"," + to_string(y) + ")";
}

class SpiralNumbers{
public:
	const int way[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	
	string getPosition(int _N){
		long long N = (long long)_N;
		long long p = 1, cnt = 0;
		for(; p * p < N; p += 2) ++cnt;
		
		int x = -cnt, y = cnt;
		long long n = p * p;
		if(n == N) return ret(x, y);
		
		for(int w = 0; w < 4; w++){
			for(int i = 1; i < p; i++){
				x += way[w][0], y += way[w][1];	
				--n;
				if(n == N) return ret(x, y);
			}
		}
	}
};
