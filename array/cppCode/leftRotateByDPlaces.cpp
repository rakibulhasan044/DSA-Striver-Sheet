#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute force approach tc -> O(n+d) sc -> O(d)
vector<int> bruteForce(vector<int>& arr, int d) {
    vector<int> temp(arr.begin(), arr.begin() + d);

    for(int i = d; i < arr.size(); i++) {
        arr[i - d] = arr[i];
    }

    for(int i = (arr.size() - d); i < arr.size(); i++){
        arr[i] = temp[i -(arr.size() - d)];
    }
    return arr;
}

//optimal because do not take extra sc -> O(d) it takes O(1)
void optimalLeftShift(vector<int>& arr, int k) {
    int left = 0, ik = k - 1, right = arr.size() - 1;
    while(left <= ik) {
        swap(arr[left], arr[ik]);
        left ++;
        ik --;
    }

    while(k <= right) {
        swap(arr[k], arr[right]);
        k ++;
        right --;
    }
    left = 0, right = arr.size() - 1;
    while(left <= right) {
        swap(arr[left], arr[right]);
        left ++;
        right --;
    }
}

int main() {
    vector<int> arr = {3,7,8,9,10,11};
    
    bruteForce(arr, 2);
    
    for(auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
