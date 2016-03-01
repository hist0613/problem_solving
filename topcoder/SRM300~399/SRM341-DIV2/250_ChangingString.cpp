#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChangingString{
public:
	int distance(string A, string B, int K){
		vector<int> diff(A.size());
		for(int i = 0; i < A.size(); i++) diff[i] = abs(A[i] - B[i]);
		
		sort(diff.rbegin(), diff.rend());
		
		int ret = 0;
		for(int i = 0; i < K; i++) if(diff[i] == 0) ret += 1;
		for(int i = K; i < diff.size(); i++) ret += diff[i];
		
		return ret;
	}
};