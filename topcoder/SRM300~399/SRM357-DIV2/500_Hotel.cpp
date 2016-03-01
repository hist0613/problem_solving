#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1101];

class Hotel{
public:
	int marketCost(int minCustomers, vector <int> customers, vector <int> cost){
		int n = customers.size();
		int max_customer = -1;
		for(int i = 0; i < n; i++) max_customer = max(max_customer, customers[i]);
		
		vector<pair<int, int> > cstcst; // cost, customer
		cstcst.push_back(make_pair(0, 0));
		for(int i = 0; i < n; i++) cstcst.push_back(make_pair(customers[i], cost[i]));
		sort(cstcst.begin(), cstcst.end());
		
		// initialize
		for(int i = 1; i <= minCustomers + max_customer; i++){
			arr[i] = 987654321;
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = cstcst[i].first; j <= minCustomers + max_customer; j++){
				arr[j] = min(arr[j], arr[j - cstcst[i].first] + cstcst[i].second);
			}
		}
		
		int result = 987654321;
		for(int i = 0; i <= max_customer; i++) result = min(result, arr[minCustomers + i]);
		
		return result;
	};
};