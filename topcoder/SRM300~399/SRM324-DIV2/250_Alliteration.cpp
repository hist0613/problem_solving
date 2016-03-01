#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Alliteration{
public:
	int count(vector <string> words){
		int ret = 0;
		
		char prev = words[0][0];
		int consc_cnt = 1;
		for(int i = 1; i < words.size(); i++){
			if(tolower(words[i][0]) != tolower(prev)){
				if(consc_cnt >= 2) ++ret;
				prev = words[i][0];
				consc_cnt = 0;
			}
			consc_cnt++;
		}
		if(consc_cnt >= 2) ++ret;
		
		return ret;
	}
};