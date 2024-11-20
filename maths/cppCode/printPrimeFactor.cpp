#include <iostream>
#include <vector>

using namespace std;

//optimal solution apx TC -> O(sqrtRoot(n) * log(n))

vector<int> primeFactoCheck(int n){
    vector<int> ans;
    for(int i = 2; i*i  <= n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

//for bigger prime number like 37 TC -> o(n)
vector<int> primeFactor(int n){
    vector<int> ans;
    for(int i = 2; i  <= n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    return ans;
}
  
int main()
{

    vector<int> result = primeFactoCheck(47);

    for (auto val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}