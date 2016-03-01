#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ParallelepipedUnion{
public:
	int getVolume(vector <string> ppd){
		vector<int> rec1_p1(3), rec1_p2(3);
		vector<int> rec2_p1(3), rec2_p2(3);
		
		stringstream ss1(ppd[0]), ss2(ppd[1]);
		ss1>>rec1_p1[0]>>rec1_p1[1]>>rec1_p1[2]>>rec1_p2[0]>>rec1_p2[1]>>rec1_p2[2];
		ss2>>rec2_p1[0]>>rec2_p1[1]>>rec2_p1[2]>>rec2_p2[0]>>rec2_p2[1]>>rec2_p2[2];
				
		int space[101][101][101] = {0};
		for(int i = rec1_p1[0]; i < rec1_p2[0]; i++)
			for(int j = rec1_p1[1]; j < rec1_p2[1]; j++)
				for(int k = rec1_p1[2]; k < rec1_p2[2]; k++)
					space[i][j][k] = 1;
		for(int i = rec2_p1[0]; i < rec2_p2[0]; i++)
			for(int j = rec2_p1[1]; j < rec2_p2[1]; j++)
				for(int k = rec2_p1[2]; k < rec2_p2[2]; k++)
					space[i][j][k] = 1;
		
		int ret = 0;
		for(int i = 0; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				for(int k = 0; k <= 100; k++)
					ret += space[i][j][k];
		
		return ret;
	}
};