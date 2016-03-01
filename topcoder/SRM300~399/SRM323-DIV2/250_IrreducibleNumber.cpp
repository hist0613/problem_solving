#include <iostream>
#include <vector>
using namespace std;

class IrreducibleNumber{
public:
	int getIrreducible(vector <int> A){
		int chk[301] = {0};
		chk[A[0]] = chk[A[1]] = chk[A[2]] = 1;
		chk[A[0] + A[1]] = chk[A[1] + A[2]] = chk[A[2] + A[0]] = 1;
		chk[A[0] + A[1] + A[2]] = 1;
		for(int i = 1; i <= 300; i++) if(!chk[i]) return i;
	}
};