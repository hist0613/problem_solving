#include <iostream>
#include <string>
using namespace std;

class SemiPerfectSquare {
public:
    string check(int N) {
        for(int b = 2; b <= 32; b++){
            for(int a = 1; a < b; a++){
                if(a * b * b == N){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};