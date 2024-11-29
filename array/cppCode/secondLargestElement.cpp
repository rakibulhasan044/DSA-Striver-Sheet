#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute force approach tc -> O(nlogn)
int bruteForce(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int secondLargest;

    for(int i = arr.size() - 2; i >= 0; i--) {
        if(arr[i] < arr[arr.size() - 1]) {
            secondLargest = arr[i];
            return secondLargest;
        }
    }
    return -1;
}

//better approach tc -> O(n)
int better(vector<int>& arr) {
    int max = arr[0];
    int secondLargest = -1;
    for(int i = 0; i< arr.size(); i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    for(int i = 0; i< arr.size(); i++) {
        if(arr[i] > secondLargest && arr[i] != max) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

//optimal approach tc -> O(n)
int optimal(vector<int> &arr) {
    int largest = arr[0];
    int secondLargest = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}


int main() {
    vector<int> arr = {1, 2, 4, 7, 7, 5};

    // int ans = bruteForce(arr);
    // cout << ans << endl;

    int res = optimal(arr);
    cout << res << endl;
}