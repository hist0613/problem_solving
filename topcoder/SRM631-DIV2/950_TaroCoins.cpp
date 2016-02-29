#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class TaroCoins{
public:
	map<long long, long long> cache;
	long long howMany(long long N){
		if(cache[N] != 0) return cache[N];
		
		long long &ret = cache[N];
		if(N & 1) return ret = howMany(N / 2);
		else return ret = howMany(N / 2) + howMany(N / 2 - 1);
	}
	long long getNumber(long long N){
		cache[0] = cache[1] = 1;
		return howMany(N);
	}
};