#include <iostream>
#include <string>
using namespace std;

class Arrows{
public:
	int longestArrow(string s){
		int ret = -1;
		for(int i = 0; i < s.size(); i++){
			for(int j = i; j < s.size(); j++){
				if(s[i] == '<'){
					int h_flag = 1, e_flag = 1;
					for(int k = i + 1; k <= j; k++){
						if(s[k] != '-') h_flag = 0;
						if(s[k] != '=') e_flag = 0;
					}	
					if(h_flag || e_flag)
						ret = max(ret, (j - i + 1));
				}
				else if(s[j] == '>'){
					int h_flag = 1, e_flag = 1;
					for(int k = i; k < j; k++){
						if(s[k] != '-') h_flag = 0;
						if(s[k] != '=') e_flag = 0;
					}
					if(h_flag || e_flag)
						ret = max(ret, (j - i + 1));
				}
			}
		}
		return ret;
	}
};