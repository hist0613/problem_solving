#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

bool is_in(int i, int a, int b){
	if(min(a, b) <= i && i <= max(a, b)) return true;
	else return false;
}

class Segments{
public:
	string intersection(vector <int> s1, vector <int> s2){
		int x1 = s1[0], y1 = s1[1], x2 = s1[2], y2 = s1[3];
		int x3 = s2[0], y3 = s2[1], x4 = s2[2], y4 = s2[3];
		
		int inter_cnt = 0;
		for(int i = -1000; i <= 1000; i++){
			for(int j = -1000; j <= 1000; j++){
				if(is_in(i, x1, x2) && is_in(i, x3, x4) &&
					is_in(j, y1, y2) && is_in(j, y3, y4)) ++inter_cnt;
			}
		}
		if(inter_cnt == 0) return "NO";
		else if(inter_cnt == 1) return "POINT";
		else return "SEGMENT";
	};
};
