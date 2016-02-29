#include <iostream>
#include <string>
using namespace std;

class OptimalList{
public:
	string optimize(string inst){
		int v = 0, h = 0;
		for(int i = 0; i < inst.size(); i++){
			switch(inst[i]){
				case 'N': v -= 1; break;
				case 'S': v += 1; break;
				case 'W': h -= 1; break;
				case 'E': h += 1; break;
			}
		}
		
		string ret = "";
		if(h > 0) ret += string(h, 'E');
		if(v < 0) ret += string(-v, 'N');
		if(v > 0) ret += string(v, 'S');
		if(h < 0) ret += string(-h, 'W');
		
		return ret;
	}
};