#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class RoadConstruction {
public:
	int getExitTime(vector <string> currentLanes) {
		int n = currentLanes.size();

		int ret = 0;
		vector<bool> yielded(n, false);
		while(true) {
			int last = -1;
			int out = -1;
			for(int i = 0; i < n; i++) {
				if(currentLanes[i].size() > 0) {
					if(yielded[i]) {
						out = i;
						break;
					}
					else {
						yielded[i] = true;
						last = i;
					}
				}
			}
			
			if(out == -1)
				out = last;

			yielded[out] = false;
			if(currentLanes[out][0] == 'D')
				return ret;
			
			currentLanes[out] = currentLanes[out].substr(1);
			++ret;
		}
	}
};