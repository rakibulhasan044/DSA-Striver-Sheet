#include <iostream>

using namespace std;

    int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }

int reverseNum(int x) {

    int revNum = 0;

    if(x > INT_MAX || x < INT_MIN) return 0;

    while(x != 0){
        int lastDigit = x % 10;
        x /= 10;

        if(revNum > (INT_MAX /10) || revNum < INT_MIN / 10) return 0;
        revNum = (revNum * 10) + lastDigit;
    }
    return revNum;
}


int main() {
    int ans = reverseNum(-88153469);
    cout << ans << endl;
}