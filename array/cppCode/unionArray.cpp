#include <iostream>
#include <vector>
#include <set>
using namespace std;

//brute force
vector<int> bruteForce(vector<int> &a, vector<int> &b) {
    set<int> st;
    vector<int> ans;

    for(auto val : a) {
        st.insert(val);
    }
    for(auto val : b) {
        st.insert(val);
    }
    for( auto val : st) {
        ans.emplace_back(val);
    }
    return ans;
}

//optimal 
vector<int> findUnion(vector<int> &a, vector<int> &b) {

    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> ans;
    
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {
            if(ans.size() == 0 || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        } else {
            if(ans.size() == 0 || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < n1) {
        if(ans.size() == 0 || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j < n2) {
        if(ans.size() == 0 || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}


int main() {

    vector<int> a = {2, 3, 4, 5};
    vector<int> b = { 1, 1,1, 6, 7};

    vector<int> ans = findUnion(a, b);
    for(auto val : ans) {
        cout << val << " ";
    }

    cout << endl;
    return 0;
}