#include <iostream>
#include <vector>
using namespace std;

class Sortness{
public:
	double getSortness(vector<int> a){
		double sum = 0;
		for(int i = 0; i < a.size(); i++){
			int left_higher = 0, right_lower = 0;
			for(int j = 0; j < i; j++) if(a[j] > a[i]) left_higher++;
			for(int j = i + 1; j < a.size(); j++) if(a[j] < a[i]) right_lower++;
			sum += (left_higher + right_lower);
		}
		return (double) sum / a.size();
	}
};