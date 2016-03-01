#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class RGBStreet{
public:
	int estimateCost(vector <string> houses){
		int n = houses.size();
		int cost[20][3] = {0};
		for(int i = 0; i < n; i++){
			stringstream ssin(houses[i]);
			ssin>>cost[i][0]>>cost[i][1]>>cost[i][2];
		}
		
		int cache[20][3] = {0};
		cache[0][0] = cost[0][0]; cache[0][1] = cost[0][1]; cache[0][2] = cost[0][2];
		for(int i = 1; i < n; i++){
			cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + cost[i][0];
			cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + cost[i][1];
			cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + cost[i][2];
		}
		return min(min(cache[n - 1][0], cache[n - 1][1]), cache[n - 1][2]);
	}
};