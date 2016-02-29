#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class ReturnToHome{
public:
	double goHome(int X, int Y, int D, int T){
		double distance = sqrt((double)X * X + Y * Y);
		if(D < T) return distance;
		else{
			if(distance - (int)(distance / D) * D == 0) return (double)((int)(distance / D) * T);
			else{
				if(D > distance) return min(min((double)T * 2, T + abs(distance - D)), distance);					
				else{
					double time_to_go = (int)(distance / D) * T;
					distance -= (int)(distance / D) * D;
					time_to_go += min((double)T, distance);
					return time_to_go;
				}
			}
		}
	}
};