#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Containers {
public:
    int wastedSpace(vector <int> containers, vector <int> packages) {
        int ans = 0;
        for (int i = 0; i < containers.size(); i++)
            ans += containers[i];

        int pi = 0, ci = 0;
        while (pi < packages.size()) {
            if (packages[pi] <= containers[ci]){
                ans -= packages[pi];
                containers[ci] -= packages[pi];
                pi++;
            }
            else {
                ci++;
            }
        }

        return ans;
    }
};