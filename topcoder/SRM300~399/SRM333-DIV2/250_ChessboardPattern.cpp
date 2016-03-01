#include <iostream>
#include <string>
#include <vector>
using namespace std;

string first_line = ".X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X";
string second_line = "X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.X.";

class ChessboardPattern{
public:
	vector<string> makeChessboard(int rows, int cols){
		vector<string> ret(rows);
		for(int i = 0; i < rows; i++){
			if(i % 2 == 0) ret[rows - 1 - i] = first_line.substr(0, cols);
			else ret[rows - 1 - i] = second_line.substr(0, cols);
		}
		return ret;
	}
};