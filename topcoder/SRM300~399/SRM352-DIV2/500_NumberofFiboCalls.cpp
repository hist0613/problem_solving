#include <vector>
using namespace std;

class NumberofFiboCalls{
public:
	vector <int> fiboCallsMade(int n){
		vector<int> result;
		if(n == 0){
			result.push_back(1);
			result.push_back(0);
		}			
		else{
			int fibo[43]={0, 1, 1};
			for(int i = 3; i <= n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
	
			result.push_back(fibo[n - 1]); 	// 0
			result.push_back(fibo[n]);		// 1
		}	
		return result;
	}
};