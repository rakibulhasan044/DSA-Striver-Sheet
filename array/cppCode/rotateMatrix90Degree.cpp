#include<iostream>
#include<vector>

using namespace std;

//brute force approach
//tc- n^2  sc->n^2
void rotate(vector<vector<int>>& matrix) {
    
    int n = matrix.size();
    vector<vector<int>> arr(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[j][n-1-i] = matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = arr[i][j];
        }
        cout << endl;
    }

}


void rotateOptimal(vector<vector<int>>& matrix) {

    int n = matrix.size();

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //reverse every row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotateOptimal(matrix);
}