#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class AzimuthMonitoring{
public:
	int getAzimuth(vector <string> instructions){
		int azimuth = 0;
		for(auto inst : instructions){
			if(inst == "LEFT") azimuth -= 90;
			else if(inst == "RIGHT") azimuth += 90;
			else if(inst == "TURN AROUND") azimuth += 180;
			else if(inst == "HALT") break;
			else if(inst.substr(0, 4) == "LEFT") azimuth -= stoi(inst.substr(5, 3));
			else if(inst.substr(0, 5) == "RIGHT") azimuth += stoi(inst.substr(6, 3));
		}
		return (azimuth + 36000) % 360;
	}
};