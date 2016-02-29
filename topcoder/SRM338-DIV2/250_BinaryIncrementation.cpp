#include <iostream>
#include <string>
using namespace std;

class BinaryIncrementation{
public:
	string plusOne(string x){
		int x10 = stoi(x, 0, 2) + 1;
		string ret = "";
		while(x10){
			ret = (x10 & 1 ? "1" : "0") + ret;
			x10 /= 2;
		}
		return ret;
	}
};