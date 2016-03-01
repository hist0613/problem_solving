#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string alphabet[20] = {"a", "b", "k", "d", "e", "g", "h", "i", "l", "m", "n", "ng", "o", "p", "r", "s", "t", "u", "w", "y"};

class TagalogDictionary{
public:
	vector<string> sortWords(vector<string> words){
		sort(words.begin(), words.end(), [](const string &a, const string &b){
			int ai = 0, bi = 0;
			while(ai < a.size() && bi < b.size()){
				string ap = a.substr(ai, 1), bp = b.substr(bi, 1);
				if(ai + 1 < a.size() && a[ai] == 'n' && a[ai + 1] == 'g'){
					ap = "ng";
					++ai;
				}
				if(bi + 1 < b.size() && b[bi] == 'n' && b[bi + 1] == 'g'){
					bp = "ng";
					++bi;
				}
				if(ap == bp){
					++ai; ++bi;
					continue;
				}
				return find(alphabet, alphabet + 20, ap) < find(alphabet, alphabet + 20, bp);;
			}
			return a.size() < b.size();
		});
		return words;		
	}
};