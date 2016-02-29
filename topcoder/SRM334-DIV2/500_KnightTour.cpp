#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define square(x) (x) * (x)

class KnightTour{
public:
	string checkTour(vector<string> cells){
		vector<pair<int, int>> points(36);
		for(int i = 0; i < 36; i++){
			points[i].first = cells[i][0] - 'A';
			points[i].second = cells[i][1] - '1';
		}
		
		int check[6][6] = {0};
		for(int i = 0; i < 36; i++)
			check[points[i].first][points[i].second] = 1;
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 6; j++)
				if(check[i][j] == 0)
					return "Invalid";
		
		points.push_back(points[0]);
		for(int i = 1; i < 37; i++)
			if(square(points[i].first - points[i - 1].first)
				+ square(points[i].second - points[i - 1].second) != 5)
				return "Invalid";
	
		return "Valid";
	}
};