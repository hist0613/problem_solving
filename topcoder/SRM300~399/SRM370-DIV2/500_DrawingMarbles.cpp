#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DrawingMarbles {
public:
    double sameColor(vector <int> colors, int r) {
        int n = 0;
        for(int i = 0; i < colors.size(); i++)
            n += colors[i];

        double ans = 0;         
        for(int i = 0; i < colors.size(); i++) {
            double p = 1.0;
            if(colors[i] < r) continue;
            for(int j = 0; j < r; j++) {
                p *= (double)(colors[i] - j) / (n - j);
            }
            ans += p;
        }
        
        return ans;
    }
};