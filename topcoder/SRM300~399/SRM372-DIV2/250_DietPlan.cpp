#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DietPlan {
public:
	string chooseDinner(string diet, string breakfast, string lunch) {
		string eaten = breakfast + lunch;
		for(int i = 0; i < eaten.size(); i++) {
			int pos = diet.find(eaten[i]);
			if(pos == string::npos) return "CHEATER";
			else diet.erase(pos, 1);
		}
		
		sort(diet.begin(), diet.end());
		return diet;
	}
};