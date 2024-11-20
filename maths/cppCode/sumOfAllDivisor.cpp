#include <iostream>

using namespace std;
int sumOfDivisors(int n) {
    int sum = 0;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                sum += j;
            }
        }
    }
    return sum;
}

int main() {
    int ans = sumOfDivisors(5);
    cout << ans << endl;
    // sumOfDivisors(4);
}