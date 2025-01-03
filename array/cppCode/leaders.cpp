/*
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

example
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]

Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
*/

/*

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> bruteForce(vector<int> & arr) {
    int n = arr.size();
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        bool leader = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j]> arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader == true) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal approach
vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    vector<int> ans;

    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    //for sort O(N log N)
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> ans = leaders(arr);

    for(auto val: ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;

}
