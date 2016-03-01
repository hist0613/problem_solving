#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

int to[1001][101];

class BusTrip{
public:
	int returnTime(int N, vector<string> _buses){
		memset(to, -1, sizeof(to));
		
		vector<vector<int>> buses(_buses.size());
		for(int i = 0; i < buses.size(); i++){
			stringstream ss(_buses[i]);
			int station;
			while(ss>>station) buses[i].push_back(station);
			
			int time = 0;
			int curr = 0;
			while(time <= 1000){
				int next = (curr + 1) % buses[i].size();
				if(to[time][buses[i][curr]] == -1) 
					to[time][buses[i][curr]] = buses[i][next];
				time += abs(buses[i][next] - buses[i][curr]);
				curr = next;
			}
		}
		
		int time = 0;
		int curr = 0;
		while(time <= 1000){
			if(to[time][curr] == -1) ++time;
			else{
				int next = to[time][curr];
				time += abs(next - curr);
				curr = next;
				if(curr == 0 && time <= 1000){
					return time;
				}
				++time;
			}
		}
		
		return -1;
	}
};