#include <iostream>
#include <string>
using namespace std;

class Palindromize{
public:
	string minAdds(string s){
		for(int i = 0; i < s.size(); i++){
			string a = s.substr(0, i);
			string b = s.substr(i);
			if(is_palindrome(b)){
				return s + string(a.rbegin(), a.rend());
			}
		}
	}
	bool is_palindrome(string s){
		return s == string(s.rbegin(), s.rend());
	}
};