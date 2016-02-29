#include <iostream>
#include <vector>
using namespace std;

class ThrowTheBall{
public:
	int timesThrown(int N, int M, int L){
		int received[50] = {0};
		int curr = 0, cnt = 0;
		while(true){
			++received[curr]; 
			if(received[curr] == M) break;
			if(received[curr] % 2 == 0) curr = (curr + L) % N;
			else curr = (curr + N - L) % N;
			++cnt;
		}
		return cnt;
	}
};