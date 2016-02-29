#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

const int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class BirthNumbersValidator{
public:
	vector<string> validate(vector<string> test){
		vector<string> ret(test.size());
		for(int idx = 0; idx < test.size(); idx++){
			string birth = test[idx];
			int yy = stoi(birth.substr(0, 2));
			int mm = stoi(birth.substr(2, 2));
			int dd = stoi(birth.substr(4, 2));

			if(!((1 <= mm && mm <= 12) || (51 <= mm && mm <= 62))){
				ret[idx] = "NO";
				continue;
			}
			mm %= 50;
			
			if(mm == 2 && yy % 4 == 0){
				if(!(1 <= dd && dd <= 29)){
					ret[idx] = "NO";
					continue;
				}
			}
			else if(!(1 <= dd && dd <= DAYS[mm])){
				ret[idx] = "NO";
				continue;
			}
			
			if(stoll(birth) % 11 != 0){
				ret[idx] = "NO";
				continue;
			}
			
			ret[idx] = "YES";
		}
		return ret;
	}
};