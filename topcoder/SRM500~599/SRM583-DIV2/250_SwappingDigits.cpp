#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string &i, const string &j) {
	if(i.size() == j.size()) {
		return i < j;
	}
	return i.size() < j.size();
}

class SwappingDigits {
public:
	string minNumber(string num) {
		int n = num.size();
		
		vector<string> nums;
		nums.push_back(num);
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				string temp = num;
				swap(temp[i], temp[j]);
				if(temp[0] != '0') nums.push_back(temp);
			}
		}
		
		sort(nums.begin(), nums.end(), comp);
		
		return nums[0];
	}
};