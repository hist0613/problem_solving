#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TurningLightOn {
public:
	int n;
	int m;
	int minFlips(vector <string> board) {
		n = board.size();
		m = board[0].size();
		
		int cnt = 0;
		while(true) {
			if(is_on(board)) break;
			for(int k = n + m - 2; k >= 0; k--) {
				for(int i = n - 1; i >= 0; i--) {
					int j = k - i;
					if(j < 0 || j >= m) continue;
					if(board[i][j] == '1') continue;
					cnt += 1;
					flip(board, i, j);
				}
			}
		}
		
		return cnt;
	}
	void flip(vector <string> &board, int row, int col) {
		for(int i = 0; i <= row; i++) {
			for(int j = 0; j <= col; j++) {
				if(board[i][j] == '0') board[i][j] = '1';
				else board[i][j] = '0';
			}
		}
	}
	bool is_on(vector <string> &board) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(board[i][j] == '0') return false;
			}
		}
		return true;
	}
};