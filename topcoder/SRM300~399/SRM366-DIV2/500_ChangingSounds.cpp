#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[51][1001] = { 0 };

class ChangingSounds {
public:
    int maxFinal(vector <int> intervals, int beginLevel, int maxLevel) {
        int n = intervals.size();
        intervals.insert(intervals.begin(), 0);  // stuff
        
        dp[0][beginLevel] = 1;
        for(int i = 1; i <= n; i++) {
            for(int volume = 0; volume <= maxLevel; volume++) {
                if(dp[i - 1][volume] == 1) {
                    if(volume + intervals[i] <= maxLevel) 
                        dp[i][volume + intervals[i]] = 1;
                    if(volume - intervals[i] >= 0) 
                        dp[i][volume - intervals[i]] = 1;
                }
            }
        }
        
        for(int volume = maxLevel; volume >= 0; volume--) {
            if(dp[n][volume] == 1) return volume;
        }
        
        return -1;
    }
};