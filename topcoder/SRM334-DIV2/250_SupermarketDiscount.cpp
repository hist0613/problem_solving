#include <iostream>
#include <vector>
using namespace std;

class SupermarketDiscount{
public:
	int minAmount(vector <int> goods){
		int sum = goods[0] + goods[1] + goods[2];
		vector<int> small;
		for(int i = 0; i < 3; i++){
			if(goods[i] >= 50) sum -= 10;
			else small.push_back(goods[i]);
		}
		int small_sum = 0;
		for(int i = 0; i < small.size(); i++)
			small_sum += small[i];
		if(small_sum >= 50) sum -= 10;
		
		return sum;
	}
};