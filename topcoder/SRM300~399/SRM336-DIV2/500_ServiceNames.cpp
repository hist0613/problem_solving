#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class ServiceNames{
public:
	vector<string> makeList(vector<string> services){
		map<string, set<string>> m;
		for(int i = 0; i < services.size(); i++){
			stringstream ss(services[i]);
			string service, input;
			ss >> service;
			while(ss >> input){
				m[input].insert(service);
			}
		}
		
		vector<string> ret;
		for(auto map_iter : m){
			string temp = map_iter.first;
			temp += " ==> ";
			for(auto set_iter : map_iter.second){
				temp += set_iter + ", ";
			}
			temp = temp.substr(0, temp.size() - 2);
			ret.push_back(temp);
		}
		
		return ret;
	}
};