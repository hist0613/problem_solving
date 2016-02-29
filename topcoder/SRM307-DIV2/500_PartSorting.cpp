#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class PartSorting{
public:
	vector <int> process(vector <int> data, int nSwaps){
		for(int start = 0; start < data.size(); start++){
			if(!nSwaps) break;
			int max_value = -1, max_idx = 0;
			for(int i = start; i < data.size(); i++)
				if(data[i] > max_value && i - start <= nSwaps)
					max_value = data[i], max_idx = i;
			for(int i = max_idx - 1; i >= start; i--){
				nSwaps--;
				swap(data[i], data[i+1]);
			}
		}
		return data;
	}
};