#include <iostream>
#include <string>
using namespace std;

class MirroredClock{
public:
	string whatTimeIsIt(string time){
		string mm = to_string((60 - stoi(time.substr(3, 2))) % 60);
		string hh = to_string(((mm == "0") ? 12 - stoi(time.substr(0, 2)) : 11 - stoi(time.substr(0, 2))) % 12);
		if(mm.size() == 1) mm = "0" + mm;
		if(hh.size() == 1) hh = "0" + hh;
		return hh + ":" + mm;
	}
};