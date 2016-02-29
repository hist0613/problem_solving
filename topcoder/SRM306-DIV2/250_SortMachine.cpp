#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class SortMachine{
public:
	int countMoves(vector <int> a){
		vector<int> sorted;
		for(int i = 0; i < a.size(); i++) sorted.push_back(a[i]);
		sort(sorted.begin(), sorted.end());
		
		int idx = 0;
		for(int i = 0; i < a.size(); i++)
			if(a[i] == sorted[idx]) ++idx;
		return a.size() - idx;				
	}
};