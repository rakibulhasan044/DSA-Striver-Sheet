#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//bruteForce
int bruteForce(vector<int> nums) {
    int n = nums.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int num = nums[i];
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] == num) {
            cnt++;
            }
        }
        if(cnt > n / 2) {
            ans = nums[i];
            return ans;
        }
    }
    return ans;
}


//better approach tc -> O(n) sc -> O(n)
int better(vector<int> &nums) {
    unordered_map <int, int> m;
    int ans;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        m[nums[i]] ++;
    }

    for(auto val: m) {
        if(val.second > n / 2) {
            ans = val.first;
            return ans;
        }
    }
    return ans;
}


//moore's voting algorithm
//optimal
int optimal(vector<int> &nums) {
    int n = nums.size();
    int cnt = 0;
    int ans;
    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            ans = nums[i];
        }
        else if(nums[i] == ans) {
            cnt ++;
        } else {
            cnt--;
        }
    }
    return ans;
}
int main() {

    vector<int> vec = {3,2,2,7,7,2,2,8,2};
    int ans = better(vec);
    cout << ans << endl;

    return 0;
}