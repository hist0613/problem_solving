#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int arr[1001][1001];

class BlockDistance{
public:
	int minDist(vector <string> oldText, vector <string> newText){
		string a = " ", b = " ";
		for(int i = 0; i < oldText.size(); i++) a += oldText[i];
		for(int i = 0; i < newText.size(); i++) b += newText[i];
		
		int an = a.size() - 1, bn = b.size() - 1;
		
		for(int i = 0; i <= an; i++)
			for(int j = 0; j <= bn; j++)
				arr[i][j] = INF;
		for(int j = 1; j <= bn; j++) arr[0][j] = 1;
		arr[0][0] = 0;
		
		for(int i = 1; i <= an; i++){
			for(int j = 1; j <= bn; j++){
				if(a[i] == b[j]) arr[i][j] = arr[i-1][j-1];
				for(int k = 1; k < j; k++) arr[i][j] = min(arr[i][j], arr[i][k] + 1);
			}
		}
		
		return (arr[an][bn] < INF ? arr[an][bn]: -1);
	}
};