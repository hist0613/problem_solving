#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jumping{
public:
	string ableToGet(int x, int y, vector <int> jump){
		long long m = 0, M = 0;
		for(int i = 0; i < jump.size(); i++){
			if(jump[i] <= m) m = m - jump[i];
			else if(jump[i] <= M) m = 0;
			else m = jump[i] - M;
			M += jump[i];	
		}
		long long rr = x * x + y * y;
		return (m * m <= rr && rr <= M * M) ? "Able" : "Not able";
	}
};