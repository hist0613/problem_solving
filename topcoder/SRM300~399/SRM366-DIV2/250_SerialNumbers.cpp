#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int sum_of_digits(const string &str) {
    int ret = 0;
    for(int i = 0; i < (int)str.size(); i++) {
        if(isdigit(str[i])) ret += str[i] - '0';
    }
    return ret;
}

bool comp(const string &i, const string &j) {
    if(i.size() == j.size()) {
        if(sum_of_digits(i) == sum_of_digits(j)) {
            return i < j;
        }
        return sum_of_digits(i) < sum_of_digits(j);
    }
    return i.size() < j.size();
}

class SerialNumbers {
public:
    vector <string> sortSerials(vector <string> serials) {
        sort(serials.begin(), serials.end(), comp);
        return serials;
    }
};