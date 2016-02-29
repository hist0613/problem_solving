#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string digit[11] = {"", "unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek"};

class EsperantoNumbers{
public:
	string nameThisNumber(int x){
		if(x <= 10) return digit[x];
		else if(x <= 19) return "dek " + digit[x % 10];
		else if(x % 10 == 0) return digit[x / 10] + "dek";
		else return digit[x / 10] + "dek " + digit[x % 10];
	}
};