#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class RugSizes{
public:
	int rugCount(int area){
		int ret = 0;
		
		int sqrtn = (int)sqrt(area);
		for(int i = 1; i <= sqrtn; i++){
			if(area % i == 0){
				int w = i, h = area / i;
				if(w % 2 == 0 && h % 2 == 0){
					if(w == h) ++ret;
					continue;
				}
				++ret;
			}			
		}
		return ret;
	}
};
