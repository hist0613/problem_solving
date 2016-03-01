#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ScoreRecomposition{
public:
	int minError(string questions, int score){
		vector<int> arr;
		for(int i = 1; i <= questions.size(); i++) arr.push_back(i);
		
		int ret = 987654321;
		do{
			int sum = 0, error = 0;
			for(int i = 0; i < questions.size(); i++){
				if(questions[i] == 'C') sum += arr[i];
				error = max(error, abs(i + 1 - arr[i]));
			}
			if(sum == score) ret = min(ret, error);
		}while(next_permutation(arr.begin(), arr.end()));
		
		return (ret == 987654321 ? -1 : ret);
	}
};