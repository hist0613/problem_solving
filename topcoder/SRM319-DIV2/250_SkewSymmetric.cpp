#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class SkewSymmetric{
public:
	int minChanges(vector <string> M){
		int n = M.size();
		vector<vector<int>> matrix(n);
		for(int i = 0; i < n; i++){
			stringstream ssin(M[i]);
			vector<int> matrix_row(n);
			for(int j = 0; j < n; j++) ssin>>matrix_row[j];
			matrix[i] = matrix_row;
		}
		
		int ret = 0;
		for(int i = 0; i < n; i++){
			if(matrix[i][i] != 0) ++ret;
			for(int j = i + 1; j < n; j++){
				if(matrix[i][j] == -matrix[j][i]) continue;
				++ret;
			}
		}
		return ret;
	}
};