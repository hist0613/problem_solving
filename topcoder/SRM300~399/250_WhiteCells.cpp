#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class WhiteCells {
public:
	int countOccupied(vector <string> board) {
		int cnt = 0;
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[i].size(); j++) {
				if((i + j) % 2 == 0 && board[i][j] == 'F') cnt++;
			}
		}
		return cnt;
	}
};