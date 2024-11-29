#include <iostream>
#include <vector>

using namespace std;

//brute force tc -> 0(n) + O(x) + O(n -x) = O(2n) = O(n) **sc -> O(n)
void bruteForce(vector<int> &arr) {
    vector<int> temp;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != 0) {
            temp.emplace_back(arr[i]);
        }
    }
    for(int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }
    for(int i = temp.size(); i < arr.size(); i++) {
        arr[i] = 0;
    }


    for(auto val : arr) {
        cout << val << " ";
    }
}


//optimal tc -> O(n), sc -> O(1)
void optimal(vector<int> &arr) {
    if(arr.size() < 1) return;
    int j = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = j + 1; i < arr.size(); i ++) {
        if(arr[i] != 0) {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main() {
    vector<int> arr = {0};
    optimal(arr);
    for(auto val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}