#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DocumentSearch{
public:
	int nonIntersecting(vector <string> docs, string search){
		string doc = "";
		for(int i = 0; i < docs.size(); i++) doc += docs[i];
		
		int idx = 0, count = 0;
		while(idx + search.size() <= doc.size()){
			if(doc.substr(idx, search.size()) == search){
				++count;
				idx += search.size() - 1;
			}
			++idx;
		}
		
		return count;
	}
};