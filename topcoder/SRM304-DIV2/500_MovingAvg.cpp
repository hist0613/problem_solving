#include<iostream>
#include<vector>
using namespace std;

class MovingAvg{
public:
	double difference(int k, vector <double> data){
		int n = data.size();
		double sum = 0;
		for(int i = 0; i < k; i++) sum += data[i];
		
		double min_avg = sum / k, max_avg = sum / k;
		for(int i = k; i < n; i++){
			sum += data[i];
			sum -= data[i - k];
			min_avg = min(min_avg, sum / k);
			max_avg = max(max_avg, sum / k);
		}
		
		return max_avg - min_avg;
	}
};
