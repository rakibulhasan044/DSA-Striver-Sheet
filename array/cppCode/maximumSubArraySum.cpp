#include <iostream>
#include <vector>

using namespace std;

int bruteForce(vector<int> &nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//optimal approach

int optimal(vector<int> &nums) {
    int sum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}


int main() {
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    int ans = optimal(nums);
    cout << ans << endl;
}