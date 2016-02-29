#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DigitsSum{
public:
	int lastDigit(int n){
		while(n >= 10){
			int temp = 0;
			while(n){
				temp += n % 10;
				n /= 10;
			}
			n = temp;
		}
		return n;
	}
};