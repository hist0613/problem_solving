#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 987654321;

class Trekking {
public:
	int isValid(string trail, string plan){
		int n = trail.size();
		int num_campings = 0;
		for(int i = 0; i < n; i++){
			if(plan[i] == 'C'){
				if(trail[i] == '^') return MAX;
				else ++num_campings;
			}			
		}
		return num_campings;
	}
	int findCamps(string trail, vector<string> plans){
		int min_nights = MAX;
		int num_plans = plans.size();
		for(int pi = 0; pi < num_plans; pi++){
			min_nights 	= min(isValid(trail, plans[pi]), min_nights);
		}
		
		return (min_nights == MAX? -1: min_nights);
	}
};