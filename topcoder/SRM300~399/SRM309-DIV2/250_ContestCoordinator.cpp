#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class ContestCoordinator{
public:
	double bestAverage(vector <int> scores){
		sort(scores.begin(), scores.end());
		double sum;
		int lo, hi;
		if(scores.size() % 2 == 1){
			sum = scores[scores.size() / 2];
			lo = hi = scores.size() / 2;
		}
		else{
			sum = scores[(scores.size() - 1) / 2] + scores[scores.size() / 2];
			lo = (scores.size() - 1) / 2;
			hi = scores.size() / 2;
		}
		
		double best = (double) sum / (hi - lo + 1);		
		while(lo - 1 >= 0 && hi + 1 < scores.size()){
			sum += scores[--lo];
			sum += scores[++hi];
			best = max(best, sum / (hi - lo + 1));
		}
		
		return best;
	}
};