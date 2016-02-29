#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HuffmanDecoding{
public:
	string decode(string archive, vector <string> dictionary){
		int idx = 0;
		string ret = "";
		while(idx < archive.size()){
			for(int i = 0; i < dictionary.size(); i++){
				if(archive.substr(idx, dictionary[i].size()) == dictionary[i]){
					ret += ('A' + i);
					idx += dictionary[i].size();
					break;
				}
			}
		}
		return ret;
	}
};