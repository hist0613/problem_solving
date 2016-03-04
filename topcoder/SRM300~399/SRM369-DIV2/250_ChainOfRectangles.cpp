#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChainOfRectangles {
public:
    int getMaximalArea(vector <int> width, vector <int> height, string _color) {
        int n = width.size();
        vector <int> color(n);
        for(int i = 0; i < n; i++) {
            switch(_color[i]) {
                case 'R': color[i] = 0; break;
                case 'G': color[i] = 1; break;
                case 'B': color[i] = 2; break;
            }
        }
        
        vector <int> area(3, 0);
        area[color[0]] = width[0] * height[0];
        for(int i = 1; i < n; i++) {
            area[color[i-1]] -= width[i] * height[i];
            area[color[i]] += width[i] * height[i];
        }
        
        return max(max(area[0], area[1]), area[2]);
    }
};