// Given a positive integer n, count the number of digits in n that divide n evenly (i.e., without leaving a remainder). Return the total number of such digits.

#include <iostream>

using namespace std;

int dividableDigitCount(int n) {
    int cnt = 0;
    int number = n;

    while(n > 0) {
        int lastDigit = n % 10;
        n /= 10;
        if(lastDigit != 0 && number % lastDigit == 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    int result = dividableDigitCount(1200);
    cout << result << endl;
}