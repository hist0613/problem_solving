#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TypoCoderDiv2{
public:
	int count(vector <int> rating){
		int prev = 500, ret = 0;
		for(int i = 0; i < rating.size(); i++){
			if(getCoder(prev) != getCoder(rating[i])) ++ret;
			prev = rating[i];
		}
		return ret;
	}
	int getCoder(int rating){
		if(rating >= 1200) return 1;
		else return 2;
	}
};