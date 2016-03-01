#include <iostream>
#include <vector>
#include <string>
using namespace std;

class VowelEncryptor{
public:
	vector<string> encrypt(vector<string> text){
		vector<string> ret;
		for(int i = 0; i < text.size(); i++){
			string temp = "";
			for(int j = 0; j < text[i].size(); j++){
				switch(text[i][j]){
					case 'a': case 'e': case 'i': case 'o': case 'u':
						continue;
					default:
						temp += text[i][j];
				}
			}
			if(temp == "") ret.push_back(text[i]);
			else ret.push_back(temp);
		}
		
		return ret;
	}
};