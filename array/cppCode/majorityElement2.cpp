#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

//brute force
vector<int> majorityElement1(vector<int>& nums) {
    int n = nums.size();
    vector<int> ls;

    for(int i = 0; i < n; i++) {
        if(ls.size() == 0 || ls[0] != nums[i]) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i]) {
                    cnt++;
                }
            }
            if(cnt > n / 3) {
                ls.push_back(nums[i]);
            }
        }
        if(ls.size() == 2) break;
    }
    return ls;
}


//better approach
vector<int> majorityElement_2(vector<int>& nums) {
    vector<int> ls;
    unordered_map<int, int> mpp;
    int n = nums.size();
    int mini = (int)(n/3) + 1;

    for(int i = 0; i < n; i++) {
        mpp[nums[i]]++;
        if(mpp[nums[i]] == mini) {
            ls.push_back(nums[i]);
        }
        if(ls.size() == 2) break;
    }
    return ls;
}


vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1, el2;
    int n = nums.size();
    vector<int> ls;

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(el1 == nums[i]) cnt1++;
        if(el2 == nums[i]) cnt2++;
    }
    int mini = (int)(n/3) + 1;
    if(cnt1>= mini) ls.push_back(el1);
    if(cnt2>= mini) ls.push_back(el2);
    return ls;
}

int main() {

    vector<int> nums = {0,0,0};
    vector<int> ans = majorityElement(nums);

    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}