#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CDPlayer{
public:
	string s = "";
	int N;
	int isRandom(vector <string> songlist, int n){
		for(int i = 0; i < songlist.size(); i++) s += songlist[i];
		N = n;
		for(int i = 0; i < min((int)s.size(), n + 1); i++)
			if(check(i)) return i;
		return -1;
	}
	bool check(int x){
		int check[26] = {0};
		for(int i = 0; i < x; i++){
			++check[s[i] - 'A'];
			if(check[s[i] - 'A'] == 2) return false;
		}
		for(int i = x; i < s.size(); i+=N){
			int check[26] = {0};
			for(int j = 0; j < N && i + j < s.size(); j++){
				++check[s[i + j] - 'A'];
				if(check[s[i + j] - 'A'] == 2) return false;
			}			
		}
		return true;
	}
};