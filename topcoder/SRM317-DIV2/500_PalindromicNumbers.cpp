#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class PalindromicNumbers{
public:
	int countPalNums(int lower, int upper){
		int ret = 0;
		long long l = lower, u = upper;
		for(int x = 1; x <= 100000; x++){
			string tmp = to_string(x);
			long long palind1 = stoll((tmp.substr(0, tmp.size() - 1) + string(tmp.rbegin(), tmp.rend())));
			long long palind2 = stoll((tmp.substr(0, tmp.size()) + string(tmp.rbegin(), tmp.rend())));
			if(l <= palind1 && palind1 <= u) ++ret;
			if(l <= palind2 && palind2 <= u) ++ret;
		}
		return ret;
	}
};