#include <iostream>

using namespace std;
int cnt = 0;

void func() {
    if(cnt == 4) {
        return;
    }
    cout << cnt << " ";
    cnt++;
    func();
}

int main() {
    func();
    cout << endl; 
}