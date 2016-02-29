#include <iostream>
#include <string>
using namespace std;

class BettingStrategy{
public:
	int finalSum(int initSum, string outcome){
		int ret = initSum, current = 1;
		for(int i = 0; i < outcome.size(); i++){
			if(ret < current) break;
			if(outcome[i] == 'W'){
				ret += current;
				current = 1;
			}
			else{
				ret -= current;
				current *= 2;
			}
		}
		return ret;
	}
};