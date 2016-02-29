#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DerivativeSequence{
public:
	vector <int> derSeq(vector <int> a, int n){
		for(int i = 0; i < n; i++){ 
			vector<int> temp;
			for(int i = 1; i < a.size(); i++)
				temp.push_back(a[i] - a[i - 1]);
			a = temp;
		}
		return a;
	}
};