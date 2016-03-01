#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DifferentStrings{
public:
	int minimize(string A, string B){
		int ret = B.size();
		for(int i = 0; i < B.size() - A.size() + 1; i++){
			int diff = 0;
			for(int j = 0; j < A.size(); j++){
				if(A[j] != B[i + j]) diff++;
			}
			ret = min(diff, ret);
		}
		return ret;
	}
};