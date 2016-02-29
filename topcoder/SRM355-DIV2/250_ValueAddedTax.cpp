#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ValueAddedTax{
public:
	double calculateFinalPrice(string product, int price, vector <string> food){
		int n = food.size();
		int is_food = 0;
		for(int i = 0; i < n; i++){
			if(food[i] == product){
				is_food = 1;
				break;
			}
		}
		
		if(is_food == 1) return (double)price * 1.1;
		else return (double)price * 1.18;
	}
};