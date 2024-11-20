#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& arr) {
    int cnt = 0, left = 0, right = arr.size() - 1;

    if(arr[0] == 0) return -1;
    while(left < right) {
        
        if(arr[left] != 0) {
            left += arr[left];
            cnt ++;
        }
        
        if(arr[left] == 0) {
            left --;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {9 ,10, 1, 2, 3, 4, 8, 0, 0, 0, 0, 0, 0, 0, 1};
    int ans = jump(arr);
    cout << ans << endl;
}