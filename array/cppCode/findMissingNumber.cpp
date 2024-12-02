#include <iostream>
#include <vector>

using namespace std;


//brute force -> tc-> O(n^2) sc -> O(1)
int bruteForce(vector<int>& nums) {

    int ans;
    for(int i = 0; i < nums.size(); i++) {
        int flag = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return ans;
}

//better approach tc -> O(n + n) => O(n), tc -> O(n)
int better(vector<int> &nums) {
    int n = nums.size();
    int ans;
    vector<int> hash(n + 1, 0);
    
    for(int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }
    
    for(int i = 0; i < hash.size(); i++) {
        if(hash[i] == 0) {
            ans = i;
            break;
        }
    }
    return ans;
}


int optimal(vector<int> &nums) {
    int a = 0;
    int b = 0;
    for(int i = 0; i < nums.size(); i++) {
        a ^= i + 1;
        b ^= nums[i];
    }
    return a^b;
}


int main() {

    vector<int> nums = {3,2,1};
    int ans = optimal(nums);
    cout<< ans << endl;

    return 0;
}