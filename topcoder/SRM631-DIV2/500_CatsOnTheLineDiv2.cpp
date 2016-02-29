#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class CatsOnTheLineDiv2{
public:
	string getAnswer(vector <int> position, vector <int> count, int time){
		vector<int> cats;
		for(int i = 0; i < position.size(); i++){
			for(int j = 0; j < count[i]; j++) cats.push_back(position[i]);
		}
		
		sort(cats.begin(), cats.end());
		
		int left = -987654321;
		for(int idx = 0; idx < cats.size(); idx++){
			if(left < cats[idx] - time) left = cats[idx] - time - 1;
			if(++left > cats[idx] + time) return "Impossible";
		}
		return "Possible";
	}
};