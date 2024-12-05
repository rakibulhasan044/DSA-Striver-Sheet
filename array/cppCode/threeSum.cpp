#include <iostream>
#include <vector>

using namespace std;

//tc -> O(n), sc -> O(1)
void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        } else if(nums[mid] == 1) {
            mid++;
        } else if(nums[mid] == 2) {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> vec = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    sortColors(vec);

    for(auto val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;

}

