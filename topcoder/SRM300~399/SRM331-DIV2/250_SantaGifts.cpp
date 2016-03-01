#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SantaGifts{
public:
	vector <string> distribute(vector<string> gifts, int N){
		vector<int> count(N);
		vector<string> ret(N);
		for(int i = 0; i < gifts.size(); i++){
			int idx = i % N;
			if(count[idx] < 4){
				count[idx]++;
				ret[idx] += " " + gifts[i];
			}
		}
		for(int i = 0; i < N; i++)
			if(count[i] > 0)
				ret[i] = ret[i].substr(1);
		return ret;
	}
};