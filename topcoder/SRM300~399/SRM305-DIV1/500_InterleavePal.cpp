#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int can_be_palindrome(int ss, int se, int ts, int te);

int cache[51][51][51][51];
string S, T;

class InterleavePal{
public:
	int longestPal(string s, string t){
		memset(cache, -1, sizeof(cache));
		S = s, T = t;
		
		int ret = 0;
		for(int ss = 0; ss <= s.size(); ss++){ for(int se = ss; se <= s.size(); se++){
			for(int ts = 0; ts <= t.size(); ts++){ for(int te = ts; te <= t.size(); te++){
				if(can_be_palindrome(ss, se, ts, te)){
					ret = max(ret, se - ss + te - ts);
				}
			}}
		}}
		
		return ret;
	}
};
int can_be_palindrome(int ss, int se, int ts, int te){
	int &ret = cache[ss][se][ts][te];
	if(ret != -1) return ret;
	ret = 0;
	
	int lenS = se - ss, lenT = te - ts;
	if(lenS == 0){
		if(lenT <= 1) ret = 1;
		else if(T[ts] == T[te-1]) ret = can_be_palindrome(ss, se, ts + 1, te - 1);
		return ret;
	}
	if(lenT == 0){
		if(lenS <= 1) ret = 1;
		else if(S[ss] == S[se-1]) ret = can_be_palindrome(ss + 1, se - 1, ts, te);
		return ret;
	}
	if(lenS >= 2 && S[ss] == S[se - 1]) ret |= can_be_palindrome(ss + 1, se - 1, ts, te);
	if(lenT >= 2 && T[ts] == T[te - 1]) ret |= can_be_palindrome(ss, se, ts + 1, te - 1);
	if(S[ss] == T[te - 1]) ret |= can_be_palindrome(ss + 1, se, ts, te - 1);
	if(T[ts] == S[se - 1]) ret |= can_be_palindrome(ss, se - 1, ts + 1, te);
	return ret;
}