#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string row = "12345678";
const string col = "abcdefgh";

class Chessboard{
public:
	string changeNotation(string cell){
		if(isdigit(cell[0])){
			int val = stoi(cell);
			return (string)"" + col[(val - 1) % 8] + row[(val - 1) / 8];
		}
		else{
			return to_string(row.find(cell[1]) * 8 + col.find(cell[0]) + 1);
		}
	}
};