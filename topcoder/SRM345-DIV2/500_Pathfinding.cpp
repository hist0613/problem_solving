#include <iostream>
#include <algorithm>
using namespace std;

class Pathfinding {
public:
	int getDirections(int tx, int ty){
		if(ty > tx) swap(tx, ty);
		if(ty >= 0){
			if(tx % 2 && ty % 2) return tx + ty + 2;
			else return tx + ty;
		}
		return 1 + getDirections(-ty, tx - 1);
	}
};