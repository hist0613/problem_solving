#include <iostream>
#include <string>
using namespace std;

class DoubleLetter{
public:
	string ableToSolve(string S){
		while(S.size() > 0){
			int len = S.size(); 
			char prev = S[0];
			for(int i = 1; i < S.size(); i++){
				if(S[i] == prev){
					S.erase(i - 1, 2);
					break;
				}
				prev = S[i];
			}
			if(S.size() == len) return "Impossible";
		}
		return "Possible";		
	}
};