#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0; 

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == k) cnt ++;
        }
    }
    return cnt;
}

int subarraySumOptimal(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;

    for(int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        int remove = preSum - k;
        if(mpp.find(remove) != mpp.end()) {
            cnt += mpp[remove];
        }
        mpp[preSum] += 1;
    }

    return cnt;
}

int main() {

    vector<int> nums = {3,-3,1,1,1};
    int ans = subarraySumOptimal(nums, 3);
    cout << ans << endl;
}