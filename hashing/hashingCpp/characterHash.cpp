#include <iostream>
using namespace std;


int main() {

    string s;
    cin >> s;

    //take hash[256] if it does not specify which type of characters 
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}