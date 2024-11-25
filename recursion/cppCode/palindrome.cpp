#include <iostream>
using namespace std;

// tc -> O(n) 
bool checkPalindrome(string str, int i) {
    if(i >= str.size()/2) return true;
    if(str[i] != str[str.size() - i - 1]) return false;
    return checkPalindrome(str, i + 1);
}

int main() {
    string str = "wow";
    bool ans = checkPalindrome(str, 0);
    cout << ans << endl;
}