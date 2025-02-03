#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int l = k + 1; l < n; l++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;

}

vector<vector<int>> fourSum2(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for(int k = j + 1; k < n; k++) {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j != i + 1 && nums[j] == nums[j -1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l) {
                long long sum = nums[i] + nums [j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}

int main() {

    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> result = fourSum(nums, 0);

    for(auto it : result) {
        for(auto val : it) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}