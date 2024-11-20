#include <iostream>

using namespace std;

//brute force TC -> O(n)
bool isPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i < n ; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

//better approach TC -> O(sqrtRoot(n))

bool isPrimeCheck(int n) {
        if(n <= 1) return false;

    for(int i = 2; (i * i) <= n ; i++) {
        if(n % i == 0) {
            return false;
            if((n / i) != i) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int ans = isPrimeCheck(49);
    cout << ans << endl;
}