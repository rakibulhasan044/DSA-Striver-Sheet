
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//TC -> O(1)
int logCount(int n) {
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

//TC -> O(n)
int countDigit(int num) {
    int totalDigits = 0;
    while(num > 0) {
        num /= 10;
        totalDigits ++;
    }
    return totalDigits;
}

int main() {
    int result = logCount(232332);
    cout << result << endl;
}