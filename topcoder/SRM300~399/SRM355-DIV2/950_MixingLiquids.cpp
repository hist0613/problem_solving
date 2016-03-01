#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool in_error(double a, double b){
	return abs(a - b) <= 1e-9;
}

class MixingLiquids{
public:
	double howMuch(vector <int> percent, vector <int> amount, int need){
		double result = 0;
		double needp = need / 100.0;
		vector<pair<double, double> > lower, upper;
		for(int i = 0; i < percent.size(); i++){
			if(percent[i] < need) lower.push_back(make_pair(percent[i]/100.0, amount[i]));
			else if(percent[i] > need) upper.push_back(make_pair(percent[i]/100.0, amount[i]));
			else result += amount[i];
		}
		
		sort(lower.rbegin(), lower.rend());
		sort(upper.begin(), upper.end());
		
		for(int i = 0; i < lower.size(); i++) cout<<lower[i].first<<' ';
		cout<<endl;
		for(int i = 0; i < upper.size(); i++) cout<<upper[i].first<<' ';
		cout<<endl;
		
		int lp = 0, up = 0;
		while(lp < lower.size() && up < upper.size()){
			double c = (upper[up].first - needp) / (needp - lower[lp].first);
			double rc = (needp - lower[lp].first) / (upper[up].first - needp);
			double lower_required = c * upper[up].second;
			double upper_required = rc * lower[lp].second;
			
			if(in_error((double)lower[lp].second, lower_required) || lower[lp].second >= lower_required){
				result += upper[up].second + lower_required; ++up;
				lower[lp].second -= lower_required;
			}
			else{
				result += lower[lp].second + upper_required; ++lp;
				upper[up].second -= upper_required;
			}
		}
		
		return result;
	};
};