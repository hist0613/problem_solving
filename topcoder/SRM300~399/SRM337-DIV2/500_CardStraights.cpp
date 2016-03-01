#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CardStraights{
public:
	int longestStraight(vector <int> cards){
		int idx = 0, zero = 0;
		while(idx < cards.size()){
			if(cards[idx] == 0){
				++zero;
				cards.erase(cards.begin() + idx);
				--idx;
			}
			++idx;
		}
		
		sort(cards.begin(), cards.end());
		cards.erase(unique(cards.begin(), cards.end()), cards.end());
		
		int ret = zero;
		for(int i = 0; i < cards.size(); i++){
			for(int j = i; j < cards.size(); j++){
				int range = cards[j] - cards[i] + 1;
				int exist = j - i + 1;
				if( range - exist <= zero ){
					ret = max(exist + zero, ret);
				}
			}
		}	
		
		return ret;
	}
};