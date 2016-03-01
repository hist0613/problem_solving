#include <string>
#include <vector>
#include <iostream>
using namespace std;

class AttendanceShort{
public:
	vector<string> shortList(vector<string> names, vector<string> attendance){
		int N = names.size();
		vector<string> result;
		for(int i = 0; i < N; i++){
			int total = 0, acnt = 0;
			for(int j = 0; j < attendance[i].size(); j++){
				if(attendance[i][j] == 'A') ++total;
				else if(attendance[i][j] == 'P') ++total, ++acnt;
			}
			double atp = (double)acnt / total;
			if(atp < 0.75) result.push_back(names[i]);
		}
		return result;
	};
};