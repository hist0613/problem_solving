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

double getDistance(pair<int, int> p1, pair<int, int> p2){
	double ret = sqrt((p1.first - p2.first) * (p1.first - p2.first) +
					(p1.second - p2.second) * (p1.second - p2.second));
	return ret;
}

class BusSeating{
public:
	double getArrangement(string leftRow, string rightRow){
		vector<pair<int, int> > empty_seat;
		for(int i = 0; i < 10; i++){
			if(leftRow[i] == '-') empty_seat.push_back(make_pair(0, i));
			if(rightRow[i] == '-') empty_seat.push_back(make_pair(2, i));
		}
		double ret = 987654321;
		for(int i = 0; i < empty_seat.size(); i++){
			for(int j = i + 1; j < empty_seat.size(); j++){
				for(int k = j + 1; k < empty_seat.size(); k++){
					double distance_sum = getDistance(empty_seat[i], empty_seat[j]) + 
										getDistance(empty_seat[j], empty_seat[k]) + 
										getDistance(empty_seat[k], empty_seat[i]);
					ret = min(ret, distance_sum);
				}
			}
		}
		return ret;
	}
};