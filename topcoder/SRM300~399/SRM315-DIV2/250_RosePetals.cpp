#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class RosePetals{
public:
	int getScore(vector <int> dice){
		int petal[7] = {0, 0, 0, 2, 0, 4, 0};
		int ret = 0;
		for(int i = 0; i < 5; i++) ret += petal[dice[i]];
		return ret;
	}
};