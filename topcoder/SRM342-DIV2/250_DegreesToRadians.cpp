#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

class DegreesToRadians{
public:
	double convertToRadians(int degrees, int minutes, int seconds){
		double degree = degrees + (minutes * 60 + seconds) / 3600.0;
		return degree * PI / 180;
	}
};