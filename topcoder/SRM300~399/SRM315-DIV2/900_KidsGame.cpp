#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class KidsGame{
public:
	// josephus problem O(N) dynamic
	int kthKid(int n, int m, int k){
		int v = 1;
		for(int L = n; L > 0; L--){
			v = (v + m - 2) % L + 1;
			if(v == k) return n + 1 - L;
			else if(v < k) k--;
		}
		return -1;
	}
};