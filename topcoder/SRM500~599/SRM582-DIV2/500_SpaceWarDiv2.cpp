#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Enemy {
public:
    int str;
    int cnt;
    bool operator < (const Enemy& e) const {
        return str < e.str;
    }
};

class SpaceWarDiv2 {
public:
    int minimalFatigue(vector<int> girl_str, vector<int> enemy_str, vector<int> enemy_cnt) {
        int gn = girl_str.size();
        int en = enemy_str.size();

        vector<Enemy> enemy(en);
        for (int ei = 0; ei < en; ei++) {
            enemy[ei].str = enemy_str[ei];
            enemy[ei].cnt = enemy_cnt[ei];
        }
        
        sort(girl_str.rbegin(), girl_str.rend());
        sort(enemy.rbegin(), enemy.rend());

        if (girl_str[0] < enemy[0].str) 
            return -1;

        int gi = 0;
        int cnt = 0;
        int ans = 0;
        for (int ei = 0; ei < en; ei++) {
            cnt += enemy[ei].cnt;
            while (gi < gn && girl_str[gi] >= enemy[ei].str) 
                ++gi;
            ans = max((cnt + gi - 1) / gi, ans);
        }

        return ans;
    }
};