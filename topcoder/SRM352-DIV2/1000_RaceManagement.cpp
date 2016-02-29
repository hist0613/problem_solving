#include <vector>
#include <iostream>
using namespace std;	

class RaceManagement{
public:
	double getPayoutFactor(vector <int> _probability, vector <int> amounts, int minimumMoney){
		int N = _probability.size(), total_amounts = 0;
		double total_prob = 1;
		
		vector<double> probability;
		for(int i = 0; i < N; i++){
			probability.push_back(_probability[i] / 100.0);
			total_amounts += amounts[i];
			total_prob *= (1 - probability[i]);
		}
		for(int i = 0; i < N; i++){
			if(_probability[i] == 100){
				if(total_amounts - amounts[i] >= minimumMoney){
					if(amounts[i] == 0) return -2;
					else return (double)minimumMoney / (total_amounts - amounts[i]);
				}
				else return -1;
			}
		}
		double sum = 0, minusX = 0, remained = 1;
		for(int i = 0; i < N; i++){
			double curr_per = (total_prob * probability[i] / (1 - probability[i]));
		    sum += curr_per * (total_amounts - amounts[i]);
		    minusX += curr_per * amounts[i];
		    remained -= curr_per;
		}
		sum += remained * total_amounts;
		
		cout<<"sum("<<sum<<") - minusX("<<minusX<<") * p >= minimumMoney"<<endl;
		if(1.0 - total_prob <= 1e-9 && sum >= (double)minimumMoney) return -2;
		else if(sum < (double)minimumMoney) return -1;
		else{
			return (sum - (double)minimumMoney) / minusX;
		}
	};
};