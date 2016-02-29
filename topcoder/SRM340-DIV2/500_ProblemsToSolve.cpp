#include <iostream>
#include <vector>
using namespace std;

class ProblemsToSolve{
public:
	int minNumber(vector<int> pleasantness, int variety){
		int n = pleasantness.size();
		int ret = n;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(abs(pleasantness[j] - pleasantness[i]) >= variety){
					ret = min(ret, calc(0, i) + calc(i, j) - 1);
				}
			}
		}
		return ret;
	}
	int calc(int l, int r){
		if(l == r) return 1;
		else if(l + 1 == r) return 2;
		else return 1 + calc(l + 2, r);
	}
};