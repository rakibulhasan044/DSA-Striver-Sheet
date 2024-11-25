#include <iostream>

using namespace std;

int sum(int n) {
    if(n < 1) return 0;
    return n + sum(n - 1);
}

void printSum(int i, int sum) {
    if(i < 1) {
        cout << sum << endl;
        return;
    }
    printSum(i - 1, sum + i);
}

int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
int res = sum(3);
cout << res << endl;

printSum(5, 0);

int fact = factorial(4);
cout << fact << endl;
}