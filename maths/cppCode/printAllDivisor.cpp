#include <iostream> 
#include <vector>
// #include <algorithm> 
using namespace std;

int main() {

    int n = 36;
    vector<int> ls;

    for(int i = 0; i*i <= n; i++ ) {
        if(n % i == 0) {
            ls.push_back(i);
            if(n / i != i) {
                ls.push_back(n / i);
            }
        }
    }

    sort(ls.begin(), ls.end());

    for(auto val: ls) {
        cout << val << " ";
    }
    cout << endl;
}