// brute force approach ->>
/*
arr[] = {1, 2, 3}, possible permutation are 3! = 6
tc -->O(n!*n), which is very high

1.generate all the permutation for given array
2.linear search
3.next index will be answer, if next does not exists then 1st index will be answer
*/

// optimal approach -->

/*
1. longest prefix match
2.after the longest prefix put the slites greater element
3.fill the remaining element as small as possible

tc--> O(3N) = O(N)
sc --> O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int idx = -1; //if index is -1 which mean given array is the biggest permutation, then reverse the array to get the 1st element

    //2 1 5 4 3 0 0
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }
    if(idx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    //swap the break point and the least largest element compare to the indx
    for(int  i = n - 1; i >= idx; i --) {
        if(nums[i] > nums[idx]) {
            swap(nums[i], nums[idx]);
            break;
        }
    }
    //reverse the remaining element after idx because, it was in decreasing order, if we put into increasing order will get the next smallest permutation
    reverse(nums.begin() + idx + 1, nums.end()); 

}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}