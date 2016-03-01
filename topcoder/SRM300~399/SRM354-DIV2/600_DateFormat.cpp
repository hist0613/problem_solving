#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class DateFormat{
public:
	string fromEuropeanToUs(vector <string> dateList){	
		int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		string data = "";
		for(int i = 0; i < dateList.size(); i++) data += dateList[i];
		cout<<data<<endl;
		
		stringstream result;
		int pre_month = 0, pre_day = 0;
		for(int i = 0; i < data.size(); i+=6){
			int month = atoi(data.substr(i, 2).c_str());
			int day = atoi(data.substr(i+3, 2).c_str());
			
			if(month > 12) swap(month, day);
			else if(day < month) swap(month, day);
			else if(day > days[month]) return "";
			cout<<"(month/day) = "<<month<<'/'<<day<<endl;

			if(month < pre_month || (month == pre_month && day <= pre_day)){
				if(day > 12 ||  month > days[day] || day < pre_month || (day == pre_month && month <= pre_day))
					return "";
				swap(month, day);
			}
			
			if(month < 10) result<<0;
			result<<month<<'/';
			if(day < 10) result<<0;
			result<<day<<' ';
			
			pre_month = month, pre_day = day;
		}
		
		string ret = result.str();
		ret.erase(ret.size()-1);
		cout<<ret<<endl;
		return ret;
	};
};