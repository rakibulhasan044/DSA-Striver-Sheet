#include <iostream>
#include <vector>

using namespace std;

//brute approach

/* 
1. find the index of 0
2. mark the all the row and col element -1 for given index pont(i, j)
3. iterate through the vector and convert -1 = 0

tc-> O((n*m)*(n+m)+(n*m)) 
overall tc will be near n^3

*/

void markRow(vector<vector<int>>& matrix, int i, int m) {
    for(int j = 0; j < m; j++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int j, int n) {
    for(int i = 0; i < n; i++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) { //n * m
            if(matrix[i][j] == 0) {
                markRow(matrix, i, m);
                markCol(matrix, j, n); //(n + m)
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

//better approach

/*
1st loop
1st need to declare vector n and vector m for the size n * m for marking 0. If 0 is found in index(2,3) in array n index 2 will be marked and in array m index 3 will be mark

2nd loop
if either of n and m index is mark convert the matrix[i][j] index into 0

tc -> (n*m) + (n*m) == n^2
sc -> O(n) + O(m) for extra row and col vector
*/

void setZeroes1(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if(n == 0 && m == 0) return;
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(row[i] || col[j] ) {
                matrix[i][j] = 0;
            }
        }
    }
}

//optimal approach
//without extra sc
/*

*/
void setZeroes2(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    // vector<int> row(n, 0); -> matrix[0][...]
    // vector<int> col(m, 0); -> matrix[...][0]

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                //mark the i-th row
                matrix[i][0] = 0;
                //mark the j-th col
                if(j != 0) {
                matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[i][0] == 0 || matrix [0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1, 1}, { 1, 0,1, 1}, {1, 1, 0, 1}, {0,1,1,1}};

    setZeroes2(matrix);

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j< matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}