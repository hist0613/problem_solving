#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr_solid[10001];
double arr_liquid[10001];

class TreasuresPacking{
public:
	double maximizeCost(vector <string> treasures, int W){
		vector<pair<int, int> > solid;
		vector<pair<int, int> > liquid;

		for (int i = 0; i < treasures.size(); i++){
			stringstream ssin(treasures[i]);
			int weight, cost;
			char type;
			ssin >> weight >> cost >> type;
			if (type == 'Y') liquid.push_back(make_pair(weight, cost));
			else solid.push_back(make_pair(weight, cost));
		}

		for (int i = 0; i < solid.size(); i++){
			for (int j = W - solid[i].first; j >= 0; j--){
				arr_solid[j + solid[i].first] = max(arr_solid[j + solid[i].first], arr_solid[j] + solid[i].second);
			}
		}

		sort(liquid.begin(), liquid.end(), [](const pair<int, int> &i, const pair<int, int> &j){
			return ((double)i.second / i.first) >((double)j.second / j.first);
		});

		if (liquid.size() > 0){
			int idx = 0;
			double unit_cost = (double)liquid[0].second / liquid[0].first;
			for (int i = 1; i <= W; i++){
				arr_liquid[i] = arr_liquid[i - 1];
				if (idx == liquid.size()) break;
				arr_liquid[i] += unit_cost;
				if (--liquid[idx].first == 0){
					++idx;
					unit_cost = (double)liquid[idx].second / liquid[idx].first;
				}
			}
		}

		double ret = 0;
		for (int i = 0; i <= W; i++){
			ret = max(ret, arr_solid[i] + arr_liquid[W - i]);
		}

		return ret;
	}
};