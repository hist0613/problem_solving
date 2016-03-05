#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BeautifulString {
public:
    int maximumLength(int countA, int countB, int maxA, int maxB) {
        long long count_a = countA;
        long long count_b = countB;
        long long max_a = maxA;
        long long max_b = maxB;
        
        if(count_a == 0 || max_a == 0) return min(count_b, max_b);
        if(count_b == 0 || max_b == 0) return min(count_a, max_a);
        
        long long ans = count_a + count_b;
        ans = min(ans, (count_b + 1) * max_a + count_b);
        ans = min(ans, (count_a + 1) * max_b + count_a);
        return ans;
    }
};