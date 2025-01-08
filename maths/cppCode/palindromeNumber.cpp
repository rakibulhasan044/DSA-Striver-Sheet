#include <iostream>

using namespace std;

bool is_palindrome(int x) {
    if(x < 0) return false;
    string str = to_string(x);
    int i = 0, j = str.length() - 1;
    while( i < j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isPalindrome(int x) {
    int ans = 0;
    int number = x;

    while(x > 0) {
        int digit = x % 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
            return 0;
        }
        ans = (ans * 10) + digit;
        x /= 10;
    }
    if(number == ans){
        return true;
    } else {
        return false;
    }
    return false;
}


int main() {
    int ans = isPalindrome(-333);
    cout << ans << endl;

    int ans2 = is_palindrome(3330);
    cout << ans2 << endl;
    return 0;
}