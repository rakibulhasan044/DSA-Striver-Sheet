#include <iostream>
using namespace std;

void reverseArray(int *arr, int l, int r) {
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1, r - 1);
}

void rev(int arr[], int i, int n) {
    if(i >= n/2) return;
    swap(arr[i], arr[n - i - 1]);
    rev(arr, i + 1, n);
}

int main () {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7};
    int arr1[] = { 10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, 0, n - 1);
    rev(arr1, 0, 6);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 6; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
}