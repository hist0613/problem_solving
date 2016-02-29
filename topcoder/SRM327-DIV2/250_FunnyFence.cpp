#include <iostream>
#include <string>
using namespace std;

class FunnyFence{
public:
	int getLength(string s){
		char prev = s[0];
		int cnt = 1, ret = 0;
		for(int i = 1; i < s.size(); i++){
			if(s[i] == prev){
				ret = max(cnt, ret);
				cnt = 0;
			}
			prev = s[i];
			cnt = cnt + 1;			
		}
		ret = max(cnt, ret);
		
		return ret;
	}
};