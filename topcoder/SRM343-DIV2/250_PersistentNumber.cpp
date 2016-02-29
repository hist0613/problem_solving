#include <iostream>
using namespace std;

class PersistentNumber{
public:
	int getPersistence(int n){
		int ret = 0;
		while(n >= 10){
			long long temp = n, next = 1;
			while(temp){
				next *= temp % 10;
				temp /= 10;
			}
			n = next;
			++ret;
		}
		return ret;
	}
};