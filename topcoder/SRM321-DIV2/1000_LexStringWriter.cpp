#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LexStringWriter{
private:
	int cache[26][50];
	int alphacnt[26];
	int first[26];
	int last[26];
public:
	int minMoves(string s){
		for(int i = 0; i < s.size(); i++) alphacnt[s[i] - 'a']++;
		for(int i = 0; i < 26; i++){
			first[i] = s.find_first_of('a' + i);
			last[i] = s.find_last_of('a' + i);
		}
		return solve(0, 0);
	}
	int solve(int alpha, int cursor){
		if(alpha == 26) return 0;
		
		int &ret = cache[alpha][cursor];
		if(ret != 0) return ret;
		
		if(first[alpha] == -1) return ret = solve(alpha + 1, cursor);
		ret = min(
			solve(alpha + 1, last[alpha]) + abs(cursor - first[alpha]),
			solve(alpha + 1, first[alpha]) + abs(cursor - last[alpha]))
			+ abs(first[alpha] - last[alpha]) + + alphacnt[alpha];
		return ret;
	}
};