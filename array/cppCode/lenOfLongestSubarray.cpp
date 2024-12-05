#include <iostream>
#include <vector>
#include <map>

using namespace std;


//bruteForce tc -> O(n^2) sc -> O(1)
int bruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    int len = 0;     //10, 5, 2, 7, 1, 9
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k) {
                len = max(len, (j - i + 1));
            }
        }
    }
    return len;
}

//better approach using hashing if array only have positive value
//optimal approach if array hs positive and negative number
//tc->O(n*logn) sc->O(n)
int better(vector<int> arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int sum = 0;
    map<int, int> preSumMap;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == k) {    
            maxLen = max(maxLen, (i + 1));
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }

    }
    return maxLen;
}

//optimal if array has 0 & positive number

int lenOfLongestSubarr(vector<int>& arr, int k) {
    int maxLen = 0;
    int n = arr.size();
    int sum = 0;
    int left = 0, right = 0;

    while(right < n) {
        sum += arr[right];
        while(left <= right && sum > k) {
            sum -= arr[left];
            left ++;
        }
        if(sum == k) {
            maxLen = max(maxLen, (right - left + 1));
        }
        right ++;
    }
    return maxLen;
}





int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int  k = 15;
    int ans = lenOfLongestSubarr(arr, k);
    cout<< ans << endl;

    return 0;
}