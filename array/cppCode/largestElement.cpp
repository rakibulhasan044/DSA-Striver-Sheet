#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& arr) {
    int max = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    vector<int> arr = {10, 40, 20, 90, 5, 65};

    int ans = func(arr);
    cout << ans << endl; 
}