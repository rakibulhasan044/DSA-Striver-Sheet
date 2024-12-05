#include<iostream>
using namespace std;

double myPow(double x, int n) {
    long binaryForm = n;
    double ans = 1;

    if(x == 0) return 0.0;
    if(n == 1) return 1.0;

    if(n < 0) {
        x = 1/x;
        binaryForm = -binaryForm;
    }

    while(binaryForm > 0) {
        if(binaryForm % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binaryForm /= 2;
    }
    return ans;
}

int main() {
    double ans = myPow(2, -2);
    cout << ans << endl;

    return 0;
}