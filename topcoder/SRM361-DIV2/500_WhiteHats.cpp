#include <iostream>
#include <vector>
using namespace std;

class WhiteHats{
public:
	int whiteNumber(vector <int> count){
		int n = count.size();
		int digit_cnt[51] = {0};
		for(int x : count) digit_cnt[x]++;
		for(int w = 0; w <= 50; w++){
			if(digit_cnt[w - 1] == w && digit_cnt[w] == n - w) return w;
		}
		return -1;
	}
};