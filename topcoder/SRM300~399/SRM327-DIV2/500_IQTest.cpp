#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IQTest{
public:
	string nextNumber(vector<int> previous){
		int n = previous.size();
		
		if(n == 1) return "AMBIGUITY";
		
		int res = 987654321;
		for(int a = -200; a <= 200; a++){
			int b = previous[1] - a * previous[0];
			if(is_right(previous, a, b)){
				if(res == 987654321) res = a * previous[n - 1] + b;
				else if(res != a * previous[n - 1] + b) return "AMBIGUITY";
			}
		}
		if(res != 987654321) return to_string(res);
		return "BUG";
	}
private:
	bool is_right(vector<int> arr, int a, int b){
		for(int i = 1; i < arr.size(); i++){
			if(arr[i] != a * arr[i - 1] + b) return false;
		}
		return true;
	}
};