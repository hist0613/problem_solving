#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Thimbles{
public:
	int thimbleWithBall(vector <string> swaps){
		int curr[4] = {0, 1, 0, 0};
		for(int i = 0; i < swaps.size(); i++){
			int x = swaps[i][0] - '0', y = swaps[i][2] - '0';
			int t = curr[x];
			curr[x] = curr[y];
			curr[y] = t;
		}
		int result;
		for(int i = 1; i <= 3; i++)
			if(curr[i] == 1)
				result = i;
		return result;
	};
};