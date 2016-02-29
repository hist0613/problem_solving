#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Egalitarianism3Easy{
public:
	int d[10][10];
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len){		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = 987654321;
				
		for(int i = 0; i < len.size(); i++) 
			d[a[i] - 1][b[i] - 1] = d[b[i] - 1][a[i] - 1] = len[i];
		
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(i != j && j != k && k != i)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					
		int ret = 1;
		for(int used = 1; used < (1 << n); used++){			
			set<int> s;
			for(int i = 0; i < n; i++){
				if((used & (1 << i)) == 0) continue;
				for(int j = i + 1; j < n; j++){
					if((used & (1 << j)) == 0) continue;
					s.insert(d[i][j]);
				}
			}
			
			if((int)s.size() == 1) ret = max(ret, (int)__builtin_popcount(used));
		}
		
		return ret;
	}
};