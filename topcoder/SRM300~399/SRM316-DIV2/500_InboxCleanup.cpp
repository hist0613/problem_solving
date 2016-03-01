#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class InboxCleanup{
public:
	int fewestClicks(string messages, int low, int high){
		int ret = 987654321;
		for(int m = low; m <= high; m++){
			int button = -1;
			for(int i = 0; i < messages.size(); i += m){
				int del = 0, total = min(m, (int)messages.size() - i);
				for(int j = 0; j < total; j++){
					if(messages[i + j] == 'D') ++del;
				}
				++button;
				if(del > 0) button += min(1 + del, 2 + (total - del));
			}	
			ret = min(ret, button);
		}
		
		return ret;
	}
};