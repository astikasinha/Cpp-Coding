#include<iostream>
#include<vector>
using namespace std;

int determinant(vector<vector<int>>& laplacian, int n) {
    if (n == 1) {
        return laplacian[0][0];
    }
    if (n == 2) {
        return laplacian[0][0] * laplacian[1][1] - laplacian[0][1] * laplacian[1][0];
    }
    int ans = 0;
    int sign = 1; 
    for (int i = 0; i < n; i++) {
        vector<vector<int>> temp(n - 1, vector<int>(n - 1));
        for (int k = 1; k < n; k++) {
            int row = 0; 
            for (int col = 0; col < n; col++) {
                if (col == i) continue;
                temp[k - 1][row] = laplacian[k][col];
                row++;
            }
        }
        ans += sign * laplacian[0][i] * determinant(temp, n - 1);
        sign = -sign; 
    }
    return ans;
}

int numberOfSpanningTrees(vector<vector<int>>& g, int n) {
    vector<vector<int>> laplacian(n - 1, vector<int>(n - 1, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i == j) {
                laplacian[i][j] = (n - 1) - 1; 
            } else {
                laplacian[i][j] = -1; 
            }
        }
    }

    /*for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i == j) {
                // Count degree for diagonal elements
                int degree = 0;
                for (int k = 0; k < n; k++) degree += g[i][k];
                laplacian[i][j] = degree;
            } else {
                // Set negative adjacency values for off-diagonal elements
                laplacian[i][j] -= g[i][j];
            }
        }
        // Adjust diagonal element by subtracting edge to 'removed' vertex
        laplacian[i][i] -= g[i][n - 1]; 
    }*/
    return determinant(laplacian, n-1);
}

int main() {
    int n = 4;
    vector<vector<int>> g = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    cout << numberOfSpanningTrees(g, n) << endl;
    return 0;
}
