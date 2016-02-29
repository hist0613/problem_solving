#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class PositiveID{
public:
	int maximumFacts(vector <string> suspects){
		int n = suspects.size();

		vector<vector<string>> facts(n);
		for(int i = 0; i < n; i++){
			string temp = "";
			for(int idx = 0; idx < suspects[i].size(); idx++){
				if(suspects[i][idx] == ','){
					facts[i].push_back(temp);
					temp = "";
					continue;
				}
				temp += suspects[i][idx];
			}
			facts[i].push_back(temp);
		}
		
		int ret = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				map<string, int> m;
				for(int k = 0; k < facts[i].size(); k++) m[facts[i][k]]++;
				for(int k = 0; k < facts[j].size(); k++) m[facts[j][k]]++;
				
				int cnt = 0;
				for(auto it = m.begin(); it != m.end(); it++){
					if(it->second > 1) ++cnt;
				}
				
				ret = max(cnt, ret);
			}
		}
		
		return ret;
	}
};