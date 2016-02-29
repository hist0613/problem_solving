#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SumOfSelectedCells{
public:
	vector<vector<int>> transpose(vector<vector<int>> arr){
		int n = arr.size();
		int m = arr[0].size();
		vector<vector<int>> ret(m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ret[j].push_back(arr[i][j]);
			}
		}
		return ret;
	}
	string hypothesis(vector <string> table){
		vector<vector<int>> arr(table.size());
		for(int i = 0; i < table.size(); i++){
			stringstream ss(table[i]);
			int val;
			while(ss>>val) arr[i].push_back(val);
		}
		
		int n = arr.size(); // height
		int m = arr[0].size(); // width
		
		if(n == m){ // square
			for(int i = 1; i < n; i++){
				for(int j = 1; j < n; j++){
					if(arr[0][0] + arr[i][j] != arr[i][0] + arr[0][j]){
						return "INCORRECT";
					}
				}
			}
			return "CORRECT";
		}
		
		if(n > m){
			arr = transpose(arr);
			swap(n, m);
		}
		for(int i = 1; i < m; i++){
			for(int j = 0; j < n; j++){
				if(arr[j][i] != arr[j][0]){
					return "INCORRECT";
				}
			}
		}
		return "CORRECT";
	}
};