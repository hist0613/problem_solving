#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool dfs(int a);

vector<pair<int, int> > knight;
bool edge[700][700];
vector<int> a_match, b_match;
vector<bool> visited;

class Knights{
public:
	int makeFriendly(int N, vector <string> pos){
		for(int i = 0; i < pos.size(); i++){
			stringstream ss(pos[i]);
			string t;
			while(ss>>t){
				int r = t[0] - 'A' + 1;
				int c = atoi(t.substr(1).c_str());
				knight.push_back(make_pair(r, c));
				cout<<"("<<r<<","<<c<<")"<<endl;
			}
		}
		
		for(int i = 0; i + 1 < knight.size(); i++){
			for(int j = i + 1; j < knight.size(); j++){
				int dr = abs(knight[i].first - knight[j].first);
				int dc = abs(knight[i].second - knight[j].second);
				if((dr == 1 && dc == 2) || (dr == 2 && dc == 1)) edge[i][j] = edge[j][i] = true;
			}
		}
		
		a_match = vector<int>(knight.size(), -1);
		b_match = vector<int>(knight.size(), -1);
		
		int size = 0;
		for(int start = 0; start < knight.size(); ++start){
			visited = vector<bool>(knight.size(), false);
			if(dfs(start)) ++size;
		}
		
		return size / 2;
	}
};
bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b = 0; b < knight.size(); ++b){
		if(edge[a][b]){
		if(b_match[b] == -1 || dfs(b_match[b])){
			a_match[a] = b;
			b_match[b] = a;
			return true;
			}
		}
	}
	return false;
}
