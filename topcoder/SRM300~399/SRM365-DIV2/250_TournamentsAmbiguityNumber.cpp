#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TournamentsAmbiguityNumber{
public:
	int scrutinizeTable(vector <string> table){
		int n = table.size();
		int ans = 0;
		for(int a = 0; a < n; a++){
			for(int b = 0; b < n; b++){
				for(int c = 0; c < n; c++){
					if(table[a][b] == '1' && table[b][c] == '1' && table[c][a] == '1') ++ans;
				}
			}
		}
		return ans;
	}
};