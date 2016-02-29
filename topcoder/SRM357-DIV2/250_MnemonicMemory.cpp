#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MnemonicMemory{
public:
	string getPhrase(string number, vector <string> dictionary){
		int n = number.size();
		vector<int> numbers(n);
		for(int i = 0; i < n; i++) numbers[i] = number[i] - '0';
		
		sort(dictionary.begin(), dictionary.end());
		
		string result = "";
		bool *chk = new bool[dictionary.size()];
		for(int i = 0; i < n; i++) chk[i] = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < dictionary.size(); j++){
				if(dictionary[j].size() == numbers[i] && chk[j] == false){
					result += dictionary[j] + " ";
					chk[j] = true;
					break;
				}
			}
		}
		
		return result.substr(0, result.size()-1);
	};
};