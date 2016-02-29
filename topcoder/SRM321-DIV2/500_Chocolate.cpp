#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Chocolate{
public:
	int minSplitNumber(int width, int height, int nTiles){
		int ret = 987654321;
		int sqroot = sqrt(nTiles);
		for(int i = 1; i <= sqroot; i++){
			if(nTiles % i != 0) continue;
			int w = i, h = nTiles / i;
			if((w == width && h == height) || 
				(h == width && w == height)) ret = min(ret, 0);
			else if((w == width && h < height) ||
					(w < width && h == height) ||
					(h == width && w < height) ||
					(h < width && w == height)) ret = min(ret, 1);
			else if((w < width && h < height) ||
					(h < width && w < height)) ret = min(ret, 2);
		}
		return (ret == 987654321? -1: ret);
	}
};