#include <iostream>
using namespace std;

class EscapeFromRectangle{
public:
	int shortest(int x, int y, int w, int h){
		return min(min(x, w-x), min(y, h-y));
	}
};