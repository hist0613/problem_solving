#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double distance(int x1, int y1, int x2, int y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

class PolyMove{
public:
	double addedArea(vector <int> x, vector <int> y){
		int n = x.size();
		vector<double> increase;
		for(int i = 0; i < n; i++)
			increase.push_back( distance(x[(i-1 +n)%n], y[(i-1 +n)%n], x[(i+1)%n], y[(i+1)%n]) / 2.0 );
		
		vector<double> arr(n);
		arr[0] = increase[0]; arr[1] = max(increase[0], increase[1]);
		for(int i = 2; i < n - 1; i++) arr[i] = max(arr[i-1], arr[i-2] + increase[i]);
		
		double ret = arr[n-2];
		
		arr[0] = 0; arr[1] = increase[1];
		for(int i = 2; i < n - 1; i++) arr[i] = max(arr[i-1], arr[i-2] + increase[i]);
		ret = max(ret, arr[n-3] + increase[n-1]);
		
		return ret;
	}
};
