#include <iostream>
using namespace std;

class AdditionCycles{
public:
	int cycleLength(int n){
		int first = n, ret = 0;
		do{
			n = (n % 10) * 10 + (n / 10 + n % 10) % 10;
			++ret;			
		}while(first != n);
		
		return ret;
	}
};