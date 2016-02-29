#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BagsQuiz{
public:
	int checkIfProper(int n, vector <string> actions){
		int *state = new int[n + 1];
		for(int i = 1; i <= n; i++) state[i] = -1;
		
		int index;		
		for(index = 0; index < actions.size(); index++){
			string action = actions[index];
			if(action.compare(0, 3, "PUT") == 0){ // PUT a INSIDE b
				int a = atoi(action.substr(4, 2).c_str());
				int b = atoi(action.substr(action.size() - 2, 2).c_str());
				// cout<<"PUT "<<a<<" INSIDE "<<b<<endl;
				
				if(state[a] != -1 || state[b] != -1){
					cout<<"Error in PUT operation"<<endl;
					return -1;
				}
		
				state[a] = b;
			}
			else if(action.compare(0, 3, "SET") == 0){	// SET a LOOSE
				int a = atoi(action.substr(4, 2).c_str());
				// cout<<"SET "<<a<<" LOOSE "<<endl;
				
				if(state[a] != -1){
					cout<<"Error in SET operation"<<endl;
					return -1;
				}
				
				for(int i = 1; i <= n; i++) if(state[i] == a) state[i] = -1;
			}
			else{	// SWAP a WITH b
				int a = atoi(action.substr(5, 2).c_str());
				int b = atoi(action.substr(action.size() - 2, 2).c_str());
				// cout<<"SWAP "<<a<<" WITH "<<b<<endl;
				
				if(state[a] != -1 || state[b] != -1){
					cout<<"Error in SWAP operation"<<endl;
					return -1;
				}
				
				vector<int> a_list, b_list;				
				for(int i = 1; i <= n; i++){
					if(state[i] == a) a_list.push_back(i);
					if(state[i] == b) b_list.push_back(i);
				}
				
				for(int i = 0; i < a_list.size(); i++) state[a_list[i]] = b;
				for(int i = 0; i < b_list.size(); i++) state[b_list[i]] = a;
			}
		}
		
		// Check	
		for(int i = 1; i <= n; i++) cout<<i<<' '<<state[i]<<endl;
		for(int i = 1; i <= n; i++) if(state[i] != -1 && state[i] < i) return -1;
		
		int result = 0;
		for(int i = 1; i <= n; i++){
			if(state[i] == -1) ++result;
		}
		
		return result;
	};
};