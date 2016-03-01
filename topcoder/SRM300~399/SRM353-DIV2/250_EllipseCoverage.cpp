#include <iostream>
#include <cmath>
using namespace std;

class EllipseCoverage{
public:
	int calculateCoverage(int x1, int y1, int x2, int y2, int d){
		int result = 0;
		for(int i = -500; i <= 500; i++){
			for(int j = -500; j <= 500; j++){
				double distance1 = sqrt((double)(x1 - i) * (x1 - i) + (y1 - j) * (y1 - j));
				double distance2 = sqrt((double)(x2 - i) * (x2 - i) + (y2 - j) * (y2 - j));
				if(distance1 + distance2 < d) ++result;
			}
		}
		return result;
	}
};