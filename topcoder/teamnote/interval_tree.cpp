#include <iostream>
using namespace std;
 
int get_min(int curr_begin, int curr_end, int target_begin, int target_end, int index);
int get_max(int curr_begin, int curr_end, int target_begin, int target_end, int index);
 
int min_arr[1 << 18], max_arr[1 << 18], base = 1 << 17;
 
int main(void){
    int N, M;
    cin>>N>>M;
    
    // initialize
    for(int i = 0; i < base * 2; i++) min_arr[i] = 9876543210;
 
    for(int i = 0; i < N; i++){
        cin>>min_arr[base + i];
        max_arr[base + i] = min_arr[base + i];
    }

    // implement/renew tree
    int curr = base / 2;
    while(curr){
        for(int i = curr; i < curr * 2; i++){
            min_arr[i] = min(min_arr[i * 2], min_arr[i * 2 + 1]);
            max_arr[i] = max(max_arr[i * 2], max_arr[i * 2 + 1]);
        }
        curr /= 2;
    }
    for(int i = 1; i <= M; i++){
        // 0-based 
        int begin, end;
        cin>>begin>>end;
        cout<<get_min(0, base, begin, end + 1, 1)<<' '<<get_max(0, base, begin, end + 1, 1)<<endl;
    }
 
    return 0;
}
int get_min(int curr_begin, int curr_end, int target_begin, int target_end, int index){
    if(curr_begin == target_begin && curr_end == target_end) return min_arr[index];
    if(curr_begin >= curr_end || curr_begin >= target_end ||
        target_begin >= curr_end || target_begin >= target_end) return 987654321;
 
    int mid = (curr_begin + curr_end) / 2;
    return min(get_min(curr_begin, mid, target_begin, min(target_end, mid), index * 2),
        get_min(mid, curr_end, max(target_begin, mid), target_end, index * 2 + 1));
}
int get_max(int curr_begin, int curr_end, int target_begin, int target_end, int index){
    if(curr_begin == target_begin && curr_end == target_end) return max_arr[index];
    if(curr_begin >= curr_end || curr_begin >= target_end ||
        target_begin >= curr_end || target_begin >= target_end) return 0;
 
    int mid = (curr_begin + curr_end) / 2;
    return max(get_max(curr_begin, mid, target_begin, min(target_end, mid), index * 2),
        get_max(mid, curr_end, max(target_begin, mid), target_end, index * 2 + 1));
}