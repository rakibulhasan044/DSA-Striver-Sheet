#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 10, n = arr.size();
    d %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    for(auto it = arr.begin(); it < arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}