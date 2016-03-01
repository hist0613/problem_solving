#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class CyclicWords{
public:
	bool isSame(string a, string b){
		if(a.size() != b.size()) return false;
		for(int i = 0; i < a.size(); i++){
			if(b == a.substr(i, a.size() - i) + a.substr(0, i)) return true;
		}
		return false;
	}
	int differentCW(vector <string> words){
		int n = words.size();
		bool *chk = new bool[words.size()];
		for(int i = 0; i < n; i++) chk[i] = false;
		
		int result = 0;
		for(int i = 0; i < n; i++){
			if(chk[i] == false){
				++result;
				for(int j = i; j < n; j++){
					if(chk[j] == false && isSame(words[i], words[j]) == true) 
						chk[j] = true;
				}
			}
		}
		
		cout<<result<<endl;
		return result;
	};
};