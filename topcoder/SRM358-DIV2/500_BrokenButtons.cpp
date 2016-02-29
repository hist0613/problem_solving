#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class BrokenButtons{
public:
	int minPresses(int page, vector <int> broken){
		bool chk[10] = {0}; // chk[i] == false then chk[i] is not broken;
		for(int i = 0; i < broken.size(); i++) chk[broken[i]] = true;
		
		int result = 987654321;
		string clicked;
		for(int target = 0; target <= 1000000; target++){
			int flag = 1;
			string temp = to_string(target);
			for(int i = 0; i < temp.size(); i++){
				if(chk[temp[i] - '0'] == true){
					flag = 0;
					break;
				}
			}
			if(flag == 1 && abs(page - atoi(temp.c_str())) + temp.size() < result){
				result = abs(page - atoi(temp.c_str())) + temp.size();
				clicked = temp;
			}
		}
		cout<<clicked<<endl;
		return min(result, abs(page - 100));
	};
};