#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int is_prefix_free(vector<string> words){
	int n = words.size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j && words[j].compare(0, words[i].size(), words[i]) == 0) return false;
	return true;
}

class PrefixFreeSets{
public:
	int maxElements(vector <string> words){
		while(is_prefix_free(words) == false){
			int n = words.size();
			int max_not_free = 0, max_iter = 0;
			for(int i = 0; i < n; i++){
				int not_free = 0;
				for(int j = 0; j < n; j++){
					if(i != j && words[j].compare(0, words[i].size(), words[i]) == 0) ++not_free;
				}
				
				if(not_free > max_not_free){
					max_not_free = not_free;
					max_iter = i;
				}
				else if(not_free == max_not_free && words[i].size() < words[max_iter].size()){
					max_iter = i;
				}
			}
			
			cout<<*(words.begin() + max_iter)<<endl;
			words.erase(words.begin() + max_iter);
		}
		return words.size();
	}
};