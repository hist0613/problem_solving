#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double cache[2][51][2501];

class Conditional{
public:
	double probability(int nDice, int maxSide, int v, int theSum){
		int maxSum = nDice * maxSide;
		cache[0][0][0] = 1.0;
		for(int dice = 0; dice < nDice; dice++){
			for(int i = 0; i <= nDice; i++){
				for(int j = 0; j <= maxSum; j++){
					if(cache[dice%2][i][j] == 0) continue;
					for(int k = 1; k <= maxSide; k++){
						if(k == v) cache[(dice+1)%2][i + 1][j + k] += (cache[dice%2][i][j] / maxSide);
						else cache[(dice+1)%2][i][j + k] += (cache[dice%2][i][j] / maxSide);
					}
					cache[dice%2][i][j] = 0;
				}
			}
		}
		double pv = 0, psum = 0;
		for(int i = 1; i <= nDice; i++){
			for(int j = 1; j <= maxSum; j++){
				pv += cache[nDice%2][i][j];
				if(j >= theSum) psum += cache[nDice%2][i][j];
			}
		}
		
		return psum / pv;
	}
};