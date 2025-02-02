#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


//brute force
int bruteForce(vector<int>& nums) {
  
    int n = nums.size();
    int longestStreak = 1;

    for(int i = 0; i < n; i++) {
        int currentNum = nums[i];
        int currentStreak = 1;

        for (int j = 0; j < n; j++) {
            if (nums[j] == currentNum + 1) {
                currentNum++;
                currentStreak++;
                j = 0; // Restart the inner loop to check for the next number in sequence
            }
        }

        longestStreak = max(longestStreak, currentStreak);
    }
    return longestStreak;
}

//better approach
int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;
    sort(nums.begin(), nums.end());

    int cnt = 1;
    int longest = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            // Skip duplicates
            continue;
        } else if (nums[i] == nums[i - 1] + 1) {
            // Part of the current consecutive sequence
            cnt++;
        } else {
            // Sequence breaks
            cnt = 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

//best approach
int longestConsecutive2(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    //the while loop will only be execute when there is no consecutive smaller in the the set for the current element
    //tc -> O(N * N) = 2N = N
    //sc -> O(N)
    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            // cout << " x in if loop :" << x<<endl;
            while(st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {104, 4, 3, 3, 5, 100, 101, 103, 102, 2, 1};
   int ans = longestConsecutive2(nums);
    cout << ans << endl;
// longestConsecutive2(nums);
    return 0;
}
