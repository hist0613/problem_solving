#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct platform{
	int x, y, c;
};
bool compare(const platform &a, const platform &b){
	return a.y < b.y;
}

class PlatformJumper{
public:
	int maxCoins(vector <string> _platforms, int v, int g){
		vector<platform> platforms;
		int N = _platforms.size();
		for(int i = 0; i < N; i++){
			stringstream ss;
			ss<<_platforms[i];
			
			platform temp;
			ss>>temp.x>>temp.y>>temp.c;
			
			platforms.push_back(temp);
		}
		
		sort(platforms.begin(), platforms.end(), compare);
		
		int maxcoin[51] = {0};
		for(int i = 0; i < N; i++){
			maxcoin[i] = platforms[i].c;
			for(int j = 0; j < i; j++){
				if((long long int)(platforms[j].x - platforms[i].x) * (platforms[j].x - platforms[i].x) * g <= (long long int)(platforms[i].y - platforms[j].y) * 2 * v * v){
					if(maxcoin[j] + platforms[i].c > maxcoin[i]){
						maxcoin[i] = maxcoin[j] + platforms[i].c;
					}
				}
			}
		}
		
		int result = -987654321;
		for(int i = 0; i < N; i++) if(maxcoin[i] > result) result = maxcoin[i];
		
		return result;
	};
};