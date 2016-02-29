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

bool isValid(int x);

char tree[1 << 20];
int missing;

class IncompleteBST{
public:
	string missingValues(vector <string> _tree){
		for(int i = 0; i < _tree.size(); i++){
			stringstream ssin(_tree[i]);
			char val;	ssin>>val;
			int num; 	ssin>>num;
			if(val == '?') missing = num;
			tree[num] = val;
		}
		string ret = "";
		for(char c = 'A'; c <= 'Z'; c++){
			tree[missing] = c;
			if(isValid(1)) ret += c;
		}
		return ret;
	}
};
bool isValid(int x){
	int maxOfLeft = x * 2;
	if(tree[maxOfLeft]){
		do{
			if(tree[maxOfLeft] > tree[x]) return false;
			maxOfLeft = maxOfLeft * 2 + 1;
		}while(tree[maxOfLeft]);
			
		if(!isValid(x * 2)) return false;
	}
	int minOfRight = x * 2 + 1;
	if(tree[minOfRight]){
		do{
			if(tree[minOfRight] <= tree[x]) return false;
			minOfRight = minOfRight * 2;
		}while(tree[minOfRight]);
		if(!isValid(x * 2 + 1)) return false;
	}
	return true;
}