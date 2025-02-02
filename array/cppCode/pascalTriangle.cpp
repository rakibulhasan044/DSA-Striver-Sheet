#include <vector>
#include <iostream>

using namespace std;

int nCr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res = res* (n - i);
        res = res/(i + 1);
    }
    return res;
}

vector<vector<int>> generate(int numRows) {

}

int main() {

    int ans = nCr(5,2);

    cout << "ans:" << ans << endl;

    return 0;
}