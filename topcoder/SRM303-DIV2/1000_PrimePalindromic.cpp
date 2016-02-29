#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void eratosthenes(void);
vector<int> factor(int n);

const int MAX_N = 10000;
vector<int> min_factor(MAX_N + 1);

class PrimePalindromic{
public:
	int count(int A, int B){
		int ret = 0;
		eratosthenes();
		for(int n = A; n <= B; n++){
			vector<int> prime = factor(n);
			do{
				string str = "";
				for(int i = 0; i < prime.size(); i++) str += to_string(prime[i]);
				if(str == string(str.rbegin(), str.rend())){
					++ret;
					break;
				}
			}while(next_permutation(prime.begin(), prime.end()));
		}
		return ret;
	}
};

void eratosthenes(void){
	min_factor[0] = min_factor[1] = -1;
	for(int i = 2; i <= MAX_N; i++) min_factor[i] = i;
	for(int i = 2; i <= MAX_N; i++){
		if(min_factor[i] == i){
			for(int p = i * i; p <= MAX_N; p += i) min_factor[p] = min(min_factor[p], i);
		}
	}
}
vector<int> factor(int n){
	vector<int> ret;
	while(n > 1){
		ret.push_back(min_factor[n]);
		n /= min_factor[n];
	}
	return ret;
}
