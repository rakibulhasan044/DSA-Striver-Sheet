#include <iostream>
#include <vector>

using namespace std;

vector <int> lsmAndGcm(int a, int b) {
    vector<int> ans;
    int ab = a * b;
    int gcd = 0;
    while (a > 0 && b > 0){
        if(a > b) {
            a %= b;  
        }
        else if( b > a) {
            b %= a;
        }
        if( a == 0) {
            gcd = b;
        }
        if (b == 0) {
            gcd = a;
        }
    }
    int lcm = ab / gcd;
    ans.push_back(lcm);
    ans.push_back(gcd);
    return ans;
}

//brute force TC -> O(n)
int gcd(int a, int b) {
    int ans = 0;
    int size = min(a, b);

    for(int i = 1; i <= size; i++) {
        if( a % i == 0 && b % i == 0) {
            ans = max(ans, i);
        }
    }
    return ans;
}

//optimal -> equilateral algorithm

int gcdFind(int a, int b) {

    if(a == b) return a;


    while (a > 0 && b > 0){
        if(a > b) {
            a %= b;  
        }
        else if( b > a) {
            b %= a;
        }
        if( a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
    }
    return 1;
}

int main() {

    int ans = gcdFind(15, 17);
    cout << ans << endl;
    vector<int> result = lsmAndGcm(5, 10);

    for(auto val : result) {
        cout << val << " ";
    }

    return 0;
}