#include <iostream>
#include <cmath>
using namespace std;

class ImprovingStatistics{
public:
	int howManyGames(int X, int Y){
		int Z = (int)(100.0 * Y / X);
		if(Z >= 99) return -1;
		else return (int)ceil((double)( (Z + 1) * X - 100 * Y ) / (99 - Z));
	}
};