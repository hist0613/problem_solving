#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class BiggestRectangleEasy{
public:
	int findArea(int N){
		int ret = 0;
		for(int i = 1; i + 3 <= N; i++){
			int area = i * ((N - 2 * i) / 2);
			ret = max(ret, area);
		}
		return ret;
	}
};