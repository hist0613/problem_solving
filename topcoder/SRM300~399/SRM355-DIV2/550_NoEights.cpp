#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class NoEights{
public:
	int smallestAmount(int low, int high){
		string L, R;
		stringstream ss;
		ss<<low<<' '<<high;
		ss>>L>>R;
				
		if(L.size() != R.size()) return 0;
		
		int ret = 0;
		for(int i = 0; i < L.size(); i++){
			if(L[i] != R[i]) break;
			if(L[i] == '8') ++ ret;
		}		
		
		return ret;
	}
};