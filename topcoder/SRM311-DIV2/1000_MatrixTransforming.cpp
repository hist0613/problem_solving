#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cache[51][51];

class MatrixTransforming{
public:
	int minPushes(vector <string> a, vector <string> b){
		int result = 0;
		for(int i = 0; i < a.size(); i++){
			for(int j = 0; j < a[i].size(); j++){
				if(a[i][j] != b[i][j]){
					if(i + 2 >= a.size() || j + 2 >= a[i].size()) return -1;
					++result;
					for(int dx = 0; dx < 3; dx++)
						for(int dy = 0; dy < 3; dy++)
							a[i + dx][j + dy] = '0' + ('1' - a[i + dx][j + dy]);
				}
			}
		}
		return result;
	}
};