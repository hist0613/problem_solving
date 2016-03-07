#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class IDNumberVerification {
public:
	string verify(string id, vector <string> regionCodes) {
		bool isValid = false;
		
		string region = string(id.begin(), id.begin() + 6);
		for(int i = 0; i < regionCodes.size(); i++) {
			if(region == regionCodes[i]) {
				isValid = true;
				break;
			}
		}
		if(!isValid)
			return "Invalid";
		cout << "region check passed" << endl;
		
		int yyyy = stoi(string(id.begin() + 6, id.begin() + 10));
		int mm = stoi(string(id.begin() + 10, id.begin() + 12));
		int dd = stoi(string(id.begin() + 12, id.begin() + 14));
		
		if(yyyy < 1900 || yyyy > 2011) return "Invalid";
		if(mm < 1 || mm > 12) return "Invalid";
		if(dd < 1 || dd > 31) return "Invalid";
		if((mm <= 7 && mm % 2 == 0) || (mm >= 8 && mm % 2 == 1)) {
			if(mm == 2) {
				if((yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 400 == 0)) {
					if(dd > 29) return "Invalid";
				}
				else if(dd > 28) return "Invalid";				
			}
			if(dd > 30) return "Invalid";
		}
		
		cout << "birthday check passed" << endl;
		
		string sequential = string(id.begin() + 14, id.begin() + 17);
		if(sequential == "000")
			return "Invalid";
		
		bool is_male = (int)(id[16] - '0') % 2 == 1 ? true : false;
		
		int checksum = 0;
		for(int i = 0; i < id.size() - 1; i++)
			checksum += (id[i] - '0') * (1 << (17 - i));
			
		for(int x = 0; x <= 10; x++) {
			if((checksum + x) % 11 == 1) {
				cout << checksum << endl;
				cout << x << ' ' << id[17] << endl;
				if(x == 10) {
					if(id[17] == 'X') break;
					else return "Invalid";
				}
				else {
					if(x != (int)(id[17] - '0')) return "Invalid";
				}
			}
		}
		
		cout << "checksum check passed" << endl;
		
		return (is_male == true ? "Male" : "Female");
	}
};