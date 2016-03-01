#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MarbleNecklace{
public:
	string normalize(string necklace){
		vector<string> list;
		for(int i = 0; i < necklace.size(); i++){
			string right = necklace.substr(i) + necklace.substr(0, i);
			string left = string(right.rbegin(), right.rend());
			list.push_back(right);
			list.push_back(left);
		}
		
		sort(list.begin(), list.end());
		
		return list[0];
	}
};