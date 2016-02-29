#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class TextStatistics{
public:
	double averageLength(string text){
		int sum = 0, count = 0;
		text += ' ';
		
		string temp = "";
		for(int i = 0; i < text.size(); i++){
			if(isalpha(text[i])) temp += text[i];
			else if(temp.size() != 0){
				++count;
				sum += temp.size();
				temp = "";
			}
		}
		
		if(count == 0) return 0;
		else return (double)sum / count;
	}
};