#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Target{
public:
	vector <string> draw(int n){
		vector <string> ret;
		ret.push_back("#");
		for(int i = 0; i < n / 4; i++)
			ret = expand(ret);
		return ret;
	}
	vector <string> expand(vector <string> inner){
		vector <string> ret(inner.size() + 4);
		int n = ret.size();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) ret[i].push_back('#');
		for(int i = 1; i + 1 < n; i++)
			for(int j = 1; j + 1 < n; j++)
				ret[i][j] = ' ';
		for(int i = 2; i + 2 < n; i++)
			for(int j = 2; j + 2 < n; j++)
				ret[i][j] = inner[i - 2][j - 2];
		return ret;
	}
};