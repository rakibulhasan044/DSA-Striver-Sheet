#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//better for sorted array
vector<int> sortedTwoSum(vector<int> nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;

    while(i < j) {
        int pairSum = nums[i] + nums[j];
        if(pairSum > target) {
            j--;
        } else if(pairSum < target) {
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans; 
        }
    }
    return ans;
}

//optimal using hashmap if sort is not allowed than use this
//tc -> O(n)
vector<int> twoSum(vector<int> nums, int target) {
    unordered_map<int, int> m;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int first = nums[i];
        int second = target - first;


        if(m.find(second) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[second]);
            return ans;
        }
        m[first] = i;
    }
    return ans;
}

int main() {

    vector<int> vec = {2, 4, 5, 7, 11};
    int target = 12;

    vector<int> ans = twoSum(vec, target);
    if (ans.empty()) {
        cout << "No pair found" << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;

}