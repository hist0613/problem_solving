#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CarolsSinging{
public:
	int choose(vector<string> lyrics){
		const int PEOPLE = lyrics.size();
		const int LYRICS = lyrics[0].size();
		
		int ret = PEOPLE;
		for(int carol = 1; carol < (1 << LYRICS); carol++){
			unsigned int flag = 0;
			for(int j = 0; j < LYRICS; j++){
				if((carol & (1 << j)) == 0) continue;
				for(int i = 0; i < PEOPLE; i++){
					if(lyrics[i][j] == 'Y')
						flag |= (1 << i);
				}
			}
			if(flag == (1 << PEOPLE) - 1)
				ret = min(ret, __builtin_popcount(carol));
		}
		
		return ret;
	}
};