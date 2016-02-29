#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class BattleshipChecker{
private:
	const int N = 10;
	const int WAYS = 4;
	const int WAY[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
public:
	string checkBoard(vector <string> board){
		int row_chk[10] = {0}, col_chk[10] = {0};
		int score = 20; string ret;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] == 'X'){
					if(row_chk[i] == 0) --score;
					if(col_chk[j] == 0) --score;
					row_chk[i] = col_chk[j] = 1;
				}
			}
		}
		ret = "ACCEPTED, " + to_string(score)+ " POINTS";
		
		int ship[5] = {0};
		int chk[10][10] = {0};
		for(int i = 0 ; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 'X' || chk[i][j]) continue;
				
				int min_x = i, max_x = i, min_y = j, max_y = j;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				chk[i][j] = 1;
				while(!q.empty()){
					int x = q.front().first, y =  q.front().second; q.pop();
					min_x = min(min_x, x); max_x = max(max_x, x);
					min_y = min(min_y, y); max_y = max(max_y, y);
					
					for(int i = 0; i < WAYS; i++){
						int nx = x + WAY[i][0], ny = y + WAY[i][1];
						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if(board[nx][ny] == 'X' && !chk[nx][ny]){
							q.push(make_pair(nx, ny));
							chk[nx][ny] = 1;
						}
					}
				}
				
				int height = max_x - min_x + 1;
				int width = max_y - min_y + 1;
				if(height > 1 && width > 1) return "REJECTED";
				if(height == 1 && width == 1) ship[1]++;
				else if(max(height, width) > 4) return "REJECTED";
				else ship[max(height, width)]++;
			}
		}
		for(int i = 1; i + 1 < N; i++){
			for(int j = 1; j + 1 < N; j++){
				if(board[i][j] == 'X'){
					if(board[i - 1][j - 1] == 'X') return "REJECTED";
					if(board[i - 1][j + 1] == 'X') return "REJECTED";
					if(board[i + 1][j - 1] == 'X') return "REJECTED";
					if(board[i + 1][j + 1] == 'X') return "REJECTED";
				}
			}
		}
		for(int i = 1; i <= 4; i++) if(ship[i] != 5 - i) return "REJECTED";
		
		return ret;
	}
};