#include <iostream>
using namespace std;


void print(int n) {
    if(n == 0) return;
    print(n - 1);
    cout << n << " ";
}

    void printGfg(int N) {
        // Code here
        if(N == 0) return;
        printGfg(N - 1);
        cout << "GFG" << " ";
    }
long long sumOfSeries(long long n) {
    if (n == 0) return 0;  
    return (n * n * n) + sumOfSeries(n - 1); 
}



int main() {
    // print(5);
    // printGfg(5);
    long long res = sumOfSeries(5);
    cout << res;
    // sumOfSeries(5);

}