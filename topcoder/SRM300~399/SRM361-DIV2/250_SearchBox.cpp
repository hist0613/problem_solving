#include <iostream>
#include <string>
using namespace std;

class SearchBox{
public:
	int find(string text, string keyword, string wholeWord, int start){
		for(int curr = start; curr + keyword.size() - 1 < text.size(); curr++){
			if(text.substr(curr, keyword.size()) == keyword){
				if(wholeWord == "Y"){
					if((curr == 0 || text[curr - 1] == ' ') && (curr + keyword.size() - 1 == text.size() - 1 || text[curr + keyword.size()] == ' ')){
						return curr;
					}
					else continue;
				}
				else{ // wholeWord == "N"
					return curr;
				}
			}
		}
		return -1;
	}
};