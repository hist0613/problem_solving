#include <iostream>
#include <string>
using namespace std;

const long long LIMIT = 1000000000000000000;

class Multifactorial{
public:
	string calcMultiFact(int n, int k){
		long long ans = n;
		n -= k;
		while(n > 0){
			if(ans <= LIMIT / n) ans *= n;
			else return "overflow";
			n -= k;
		}
		return to_string(ans);
	}
};