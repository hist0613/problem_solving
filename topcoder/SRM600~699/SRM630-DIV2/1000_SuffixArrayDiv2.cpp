#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class SuffixArrayDiv2{
public:
	vector<int> getSuffixArray(string s){
		vector<pair<string, int>> sv(s.size());
		for(int i = 0; i < s.size(); i++){
			sv[i].first = s.substr(i);
			sv[i].second = i;
		}
		
		sort(sv.begin(), sv.end());
		
		vector<int> ret(s.size());
		for(int i = 0; i < s.size(); i++) ret[i] = sv[i].second;
		
		return ret;
		
	}
	bool isSameVector(vector<int> a, vector<int> b){
		if(a.size() != b.size()) return false;
		int n = a.size();
		for(int i = 0; i < n; i++)
			if(a[i] != b[i])
				return false;
		return true;
	}
	string smallerOne(string s){
		vector<int> original = getSuffixArray(s);
		for(int i = 0; i < s.size(); i++){
			string t = s;
			if(--t[i] < 'a') continue;
			
			vector<int> temp = getSuffixArray(t);
			if(isSameVector(original, temp)) return "Exists";						
		}
		return "Does not exist";
	}
};