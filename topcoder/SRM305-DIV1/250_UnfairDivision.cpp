#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class UnfairDivision{
public:
	int albertsShare(vector <int> assets){
		int ret = 0;
		for(int cut1 = 1; cut1 < assets.size(); cut1++){
			vector<int> m(3);
			for(int cut2 = 1; cut2 < assets.size(); cut2++){				
				if(cut1 == cut2) continue;
				
				vector<int> p(3);
				
				int idx = 0;
				for(int i = 0; i < assets.size(); i++){
					if(i == cut1 || i == cut2) ++idx;
					p[idx] += assets[i];
				}

				sort(p.begin(), p.end(), greater<int> ());
				swap(p[0], p[1]);
				
				m = max(m, p);
			}
			ret = max(ret, m[2]);			
		}
		return ret;
	}
};