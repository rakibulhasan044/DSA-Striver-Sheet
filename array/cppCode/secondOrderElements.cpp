#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//tc -> O(n)
int secondLargestFunc(vector<int> &arr) {
    int largest = arr[0];
    int secondLargest = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int secondSmallestFunc(vector <int>& arr) {
    int smallest = arr[0];
    int secondSmallest = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            secondSmallest = smallest;
        }
        else if(arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

vector<int> getSecondOrderElements(vector<int> arr)  {
    int secondLargest = secondLargestFunc(arr);
    int secondSmallest = secondSmallestFunc(arr);
    return {secondLargest, secondSmallest};
}

int main() {
    vector<int> arr = {10, 5, 2, 10, 8};
    vector <int> res = getSecondOrderElements(arr);
    for(auto value : res) {
        cout << value << " ";
    }
    cout << endl;
}