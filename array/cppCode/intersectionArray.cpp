#include <iostream>
#include <vector>

using namespace std;

// brute force approach tc -> O(n * m) => O(n^2), sc -> O(m)
vector<int> bruteForce(vector<int> &a,int n, vector<int> &b, int m) {
    vector<int> ans;
    vector<int> visit(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j] && visit[j] == 0) {
                ans.push_back(a[i]);
                visit[j] = 1;
                break;
            }
            else if(b[j] > a[i]) break;
        }
    }
    return ans;
}

//optimal approach tc -> O(n + m) => O(n), sc -> O(1)
vector<int> optimal(vector<int> &a,int n, vector<int> &b, int m) {
    int i = 0, j = 0;
    vector<int> ans;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            i++;
        } else if(b[j] < a[i]) {
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {

    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 6, 7};
    int n = a.size(), m = b.size();
    vector<int> ans = optimal(a, n, b, m);
    for(auto val : ans) {
        cout << val << " ";
    }
    
    cout << endl;
    return 0;
}