#include <vector>
#include <algorithm>
using namespace std;

class SumsOfPerfectPowers{
public:
	int howMany(int lowerBound, int upperBound){
		bool check[5000010] = {0};
		vector<int> pplist;
		
		pplist.push_back(0);
		pplist.push_back(1);
		check[0] = check[1] = true;
		
		for(int i = 2; i <= 5000000; i++){
			if(!check[i]){
				long long int p = (long long int)i * i;
				while(p <= 5000000){
					pplist.push_back((int)p);
					check[p] = true;
					p *= i;
				}
			}
		}
		sort(pplist.begin(), pplist.end());
		
		bool ppcheck[5000010] = {0};
		int n = pplist.size();
		int result = 0;
		
		for(int i = 0; i < n; i++){
			int a = pplist[i];
			for(int j = 0; j < n; j++){
				int b = pplist[j];
				if(lowerBound <= a + b && a + b <= upperBound && !ppcheck[a + b]){
					result ++;
					ppcheck[a + b] = true;
				}					
			}
		}
		
		return result;
	};
};