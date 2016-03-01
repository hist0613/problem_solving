#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

double Area(int A, int B, int C);
double calc(int can_used);

int n;
vector<int> fence;
double cache[65537];

class GrasslandFencer{
public:
	double maximalFencedArea(vector <int> fences){
		for(int i = 0; i < 65537; i++) cache[i] = -1;
		n = fences.size();
		fence = fences;
		sort(fence.begin(), fence.end());
		
		return calc((1 << n) - 1);
	}
};

double Area(int A, int B, int C){
	double p = (A + B + C) / 2.0;
	double area = sqrt(p * (p - A) * (p - B) * (p - C));
	return area;
}
double calc(int can_used){
	if(cache[can_used] != -1) return cache[can_used];
	
	vector<int> left;
	for(int i = 0; i < n; i++) 
		if(can_used & (1 << i)) left.push_back(i);
	
	double &ret = cache[can_used];
	ret = 0;
	for(int i = 0; i < left.size(); i++){
		for(int j = i + 1; j < left.size(); j++){
			for(int k = j + 1; k < left.size(); k++){
				if(fence[left[i]] + fence[left[j]] <= fence[left[k]]) continue;
				double curr = Area(fence[left[i]], fence[left[j]], fence[left[k]]);
				curr += calc(can_used & ~(1 << left[i] | 1 << left[j] | 1 << left[k]));
				ret = max(ret, curr);
			}
		}
	}
	
	return ret;
}