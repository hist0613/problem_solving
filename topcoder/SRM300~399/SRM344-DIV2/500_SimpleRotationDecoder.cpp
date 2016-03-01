#include <iostream>
#include <string>
using namespace std;

const string alpha = " abcdefghijklmnopqrstuvwxyz";

class SimpleRotationDecoder{
public:
	string decode(string cipherText){
		for(int a = 1; a < 27; a++){
			for(int b = 1; b < 27; b++){
				for(int c = 1; c < 27; c++){
					string password = (string)"" + alpha[a] + alpha[b] + alpha[c];
					string original = "";
					for(int i = 0; i < cipherText.size(); i++)
						original += alpha[(alpha.find(cipherText[i]) + 27 - alpha.find(password[i % 3])) % 27];
					if(is_right_text(original))
						return original;
				}
			}
		}
		return cipherText;
	}
	bool is_right_text(string original){
		string temp = "";
		for(int i = 0; i < original.size(); i++){
			if(original[i] == ' '){
				if(!is_right_word(temp)) return false;
				temp = "";
				continue;
			}
			temp += original[i];
		}
		if(!is_right_word(temp)) return false;
		return true;
	}
	bool is_right_word(string word){
		if(word.size() < 2 || word.size() > 8) return false;
		int flag = 0;
		for(int i = 0; i < word.size(); i++){
			if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
				flag = 1;
				break;
			}
		}
		if(flag == 0) return false;
		return true;
	}
};