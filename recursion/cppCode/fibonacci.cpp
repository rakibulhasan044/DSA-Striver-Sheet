#include <iostream>

using namespace std;

int num(int n) {
    if(n <= 1) return n;
    return num(n - 1) + num(n - 2);
}

int main() {
    int res = num(2);
    cout << res << endl;
}