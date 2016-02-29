#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class VowelLatin{
public:
	string vowel = "aeiou";
	string translate(string word){
		string ret1 = "", ret2 = "";
		for(int i = 0; i < word.size(); i++){
			if(vowel.find(tolower(word[i])) != -1)
				ret2 += word[i];
			else 
				ret1 += word[i];
		}
		return ret1 + ret2;
	}
};