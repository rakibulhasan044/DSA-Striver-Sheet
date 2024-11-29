#include <iostream>
#include <vector>
#include <set>
using namespace std;

//brute force tc -> O(nlogn + n)
int brute(vector<int>& arr) {
    set<int> st;
    int index = 0;
    for(int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]); //for set to insert tc -> O(nlogn)
    }

    for(auto val : st) {
        arr[index] = val;
        index ++;
    }
    return index;
}

//optimal tc -> O(n)

int optimal(vector<int>& arr) {
    int i = 0;
    for(int j = 1; j < arr.size(); j++) {
        if(arr[i] != arr[j]) {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}


int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};

    // int ans = brute(arr);
    // cout << ans << endl;
    int ans1 = optimal(arr);
    cout << ans1 << endl;

}