#include<string>
#include<iostream>
using namespace std;

struct DistanceBetweenStrings{
	int getDistance(string a, string b, string letterSet){
		int ret = 0;
		for(int i = 0; i < letterSet.size(); i++){
			int sum = 0;
			for(int j = 0; j < a.size(); j++)
				if(tolower(a[j]) == letterSet[i]) ++sum;
			for(int j = 0; j < b.size(); j++)
				if(tolower(b[j]) == letterSet[i]) --sum;
			ret += sum * sum;
		}
		return ret;
	}
};