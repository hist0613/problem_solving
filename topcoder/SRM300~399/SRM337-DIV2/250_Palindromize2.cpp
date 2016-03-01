#include <iostream>
#include <string>
using namespace std;

class Palindromize2{
public:
	string minChanges(string s){
		for(int i = 0; i < s.size() / 2; i++)
			s[i] = s[s.size() - 1 - i] = min(s[i], s[s.size() - 1 - i]);
		return s;
	}
};