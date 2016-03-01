#include <iostream>
using namespace std;

class PaperAndPaintEasy{
public:
	long long computeArea(int width, int height, int xfold, int cnt, int x1, int y1, int x2, int y2){
		long long fw = x2 - x1, fy = y2 - y1;
		long long painted = fw * fy * (cnt + 1);
		xfold = min(xfold, width - xfold);
		if(x2 <= xfold) painted *= 2;
		else if(x1 <= xfold && xfold <= x2) painted += (xfold - x1) * fy * (cnt + 1);
		return (long long)width * height - painted;
	}
};