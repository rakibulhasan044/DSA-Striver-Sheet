#include <iostream>

using namespace std;

bool isArmstrong(int num) {
    int duplicate = num;
    int ans = 0;

    while(num > 0) {
        int lastDigit = num % 10;
        ans  += lastDigit * lastDigit * lastDigit;
        num /= 10; 
    }
    if(duplicate == ans) return true;
    return false;
}

int main() {
    bool ans = isArmstrong(4072);
    cout << ans << endl;
}