#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class MeasuringTemperature{
public:
	double averageTemperature(vector <int> measured){
		int n = measured.size();
		vector<int> valid(n);
		for(int i = 0; i < n; i++){
			if(measured[i] < -273) continue;
			for(int j = max(0, i - 2); j <= min(n - 1, i + 2); j++){
				if(i == j || abs(measured[i] - measured[j]) > 2) continue;
				valid[i] = 1;
				break;
			}
		}
		
		int valid_cnt = 0;
		double sum = 0;
		for(int i = 0; i < n; i++){
			if(valid[i] == 1){
				++valid_cnt;
				sum += measured[i];
			}
		}
		
		if(valid_cnt == 0) return -300.0;
		return sum / valid_cnt;
	}
};