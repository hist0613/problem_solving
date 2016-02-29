#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class LightsCube{
public:
	struct point{
		int x, y, z;
	};
	vector <int> count(int N, vector <string> _lights){
		int n = _lights.size();
		
		vector<point> lights(n);
		for(int i = 0; i < n; i++){
			stringstream ss(_lights[i]);
			ss>>lights[i].x>>lights[i].y>>lights[i].z;
		}
		
		vector<int> ret(n);
		for(int x = 0; x < N; x++){
			for(int y = 0; y < N; y++){
				for(int z = 0; z < N; z++){
					int dist = 987654321, m = 0;
					for(int i = 0; i < n; i++){
						int d = abs(x - lights[i].x) + abs(y - lights[i].y) + abs(z - lights[i].z);
						if(d < dist){
							dist = d;
							m = i;
						}
					}
					ret[m]++;
				}
			}
		}
		
		return ret;
	}
};