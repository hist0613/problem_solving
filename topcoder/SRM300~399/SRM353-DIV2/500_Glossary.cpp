#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Glossary{
public:
	vector <string> buildGlossary(vector <string> items){
		sort(items.begin(), items.end(),
			[](const string &a, const string &b){
				for(int i = 0; i < min(a.size(), b.size()); i++)
					if(tolower(a[i]) != tolower(b[i]))
						return tolower(a[i]) < tolower(b[i]);
				return a.size() < b.size();
			}
		);
		
		vector<string> left_list, right_list;
		char pre_alpha = 'A' - 1;
		for(int i = 0; i < items.size(); i++){
			char alpha = toupper(items[i][0]);
			if(alpha <= 'M'){
				if(alpha > pre_alpha){
					pre_alpha = alpha;
					stringstream ss;
					ss<<pre_alpha<<"                    ";
					left_list.push_back(ss.str());
					left_list.push_back("-------------------  ");
				}
				string temp = "  " + items[i];
				while(temp.size() < 21) temp = temp + " ";
				left_list.push_back(temp);
			}
			else{
				if(alpha > pre_alpha){
					pre_alpha = alpha;
					stringstream ss;
					ss<<pre_alpha<<"                  ";
					right_list.push_back(ss.str());
					right_list.push_back("-------------------");
				}
				string temp = "  " + items[i];
				while(temp.size() < 19) temp = temp + " ";
				right_list.push_back(temp);
			}
		}
		
		vector<string> result;
		for(int i = 0; i < left_list.size(); i++){
			if(i < right_list.size())
				result.push_back(left_list[i] + right_list[i]);
			else
				result.push_back(left_list[i] + "                   ");
		}
		for(int i = left_list.size(); i < right_list.size(); i++)
			result.push_back("                     " + right_list[i]);
			
		// for(int i = 0; i < result.size(); i++) cout<<"\""<<result[i]<<"\""<<endl;
		return result;
	};
};