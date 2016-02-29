#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long Median(void);
void Add(long long x);
void Del(long long x);

const long long MOD = 65536;

long long tree[MOD * 2 + 1];
int K;

class FloatingMedian{
public:
	long long sumOfMedians(int seed, int mul, int add, int N, int k){
		K = k;
		
		vector<long long> arr(N);
		arr[0] = seed;
		for(int i = 1; i < N; i++) arr[i] = (arr[i-1] * mul + add) % MOD;
		
		long long ret = 0;

		for(int i = 0; i < K; i++) Add(arr[i]);
		ret += Median();
		
		for(int i = K; i < N; i++){
			Del(arr[i - k]);
			Add(arr[i]);
			ret += Median();
		}
		
		return ret;
	}
};
long long Median(void){
	long long idx = 1;
	int tempK = (K + 1) / 2;
	while(idx < MOD){
		if(tempK <= tree[idx * 2]) idx *= 2;
		else{
			tempK -= tree[idx * 2];
			idx = 2 * idx + 1;

		}
	}
	return idx - MOD;
}
void Add(long long x){
	x = x + MOD;
	while(x > 0){
		tree[x]++;
		x /= 2;
	}
}
void Del(long long x){
	x = x + MOD;
	while(x > 0){
		tree[x]--;
		x /= 2;
	}
}