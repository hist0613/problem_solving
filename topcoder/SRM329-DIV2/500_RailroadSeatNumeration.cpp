#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RailroadSeatNumeration{
public:
	int dom_to_inter(int x){
		int ret = 10 * ((x + 3) / 4);
		if(x % 4 == 1) ret += 1;
		else if(x % 4 == 2) ret += 3;
		else if(x % 4 == 3) ret += 4;
		else if(x % 4 == 0) ret += 6;
		return ret;
	}
	bool check_dom(int x){
		return 1 <= x && x <= 36;
	}
	bool check_inter(int x){
		int a = x / 10, b = x % 10;
		return 1 <= a && a <= 9 && (b == 1 || b == 3 || b == 4 || b == 6);
	}
	string getInternational(vector<int> tickets){
		int d_flag = 1, i_flag = 1;
		for(int i = 0; i < tickets.size(); i++){
			if(check_dom(tickets[i]) == false) d_flag = 0;
			if(check_inter(tickets[i]) == false) i_flag = 0;
		}
		if(d_flag == 0 && i_flag == 0)
			return "BAD DATA";
		if(d_flag == 1 && i_flag == 1) 
			return "AMBIGUOUS";
		
		string ret = "";
		for(int i = 0; i < tickets.size(); i++){
			if(d_flag == 1) ret += " " + to_string(dom_to_inter(tickets[i]));
			else ret += " " + to_string(tickets[i]);
		}
		
		ret = ret.substr(1);
		return ret;
	}
};