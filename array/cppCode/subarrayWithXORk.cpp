#include <iostream>
#include <vector>
#include <map>

using namespace std;


int subarrayXor1(vector<int>& arr, int l) {
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j< n; j++) {
            int ans = 0;
            for(int k = i; k <= j; k++) {
                ans ^= arr[k];
            }
            if(ans == l) cnt++;
        }
    }
    return cnt;
}

int subarrayXor2(vector<int>& arr, int l) {
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int ans = 0;
        for(int j = i; j< n; j++) {
            ans ^= arr[j];
            if(ans == l) cnt++;
        }
    }
    return cnt;
}

int subarrayXor(vector<int>& arr, int k) {
    int n = arr.size();
    int cnt = 0;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;

    for(int i = 0; i < n; i++) {
        xr ^= arr[i];
        int x = xr ^ k;
        cnt +=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main() {
    vector<int> arr = {4,2,2,6,4};
    int result = subarrayXor(arr, 6);
    cout<< result << endl;
    return 0;
}