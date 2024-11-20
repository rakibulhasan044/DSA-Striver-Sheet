#include <iostream>
using namespace std;

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

int main() {

    int ans = gcd(13, 12);
    cout << ans << endl;

    return 0;
}