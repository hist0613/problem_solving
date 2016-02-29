#include <iostream>
#include <string>
using namespace std;

class KLastNonZeroDigits{
public:
	string getKDigits(int N, int K){
		long long fact = N;
		for(int i = 2; i < N; i++) fact *= i;
		while(fact % 10 == 0) fact /= 10;
		string ret = to_string(fact);
		if(ret.size() > K) return ret.substr(ret.size() - K);
		else return ret;
	}
};