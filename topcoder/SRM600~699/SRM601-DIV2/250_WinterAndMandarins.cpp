#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class WinterAndMandarins{
public:
	int getNumber(vector <int> bags, int K){
		sort(bags.begin(), bags.end());
		int ret = 1000000000;
		for(int i = 0; i + K - 1 < bags.size(); i++)
			ret = min(ret, bags[i + K - 1] - bags[i]);
		return ret;
	}
};