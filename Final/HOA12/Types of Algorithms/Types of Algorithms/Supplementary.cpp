#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int M = 4;
const int N = 4;



int countPaths(int mat[M][N], int i, int j, int cost) {
    // Out of the matrix, or the cost is already used up
    if (i >= M || j >= N || cost < 0)
        return 0;

    // Spend this cell's cost
    cost -= mat[i][j];

    // Base case: destination cell, valid only if the cost is exactly used up
    if (i == M - 1 && j == N - 1)
        return (cost == 0) ? 1 : 0;

    // Recursive case: go right + go down
    return countPaths(mat, i, j + 1, cost) + countPaths(mat, i + 1, j, cost);
}


int countPathsMemo(int mat[M][N], int i, int j, int cost,
                   vector<vector<vector<int>>> &memo) {
    if (i >= M || j >= N || cost < 0)
        return 0;

    cost -= mat[i][j];
    if (cost < 0)
        return 0;

    if (i == M - 1 && j == N - 1)
        return (cost == 0) ? 1 : 0;

    if (memo[i][j][cost] != -1)
        return memo[i][j][cost];

    memo[i][j][cost] = countPathsMemo(mat, i, j + 1, cost, memo)
                     + countPathsMemo(mat, i + 1, j, cost, memo);
    return memo[i][j][cost];
}


void printPaths(int mat[M][N], int i, int j, int cost, string path) {
    if (i >= M || j >= N || cost < 0)
        return;

    cost -= mat[i][j];
    path += "(" + to_string(i) + "," + to_string(j) + ")=" + to_string(mat[i][j]);

    if (i == M - 1 && j == N - 1) {
        if (cost == 0)
            cout << "  " << path << endl;
        return;
    }

    path += " -> ";
    printPaths(mat, i, j + 1, cost, path);
    printPaths(mat, i + 1, j, cost, path);
}

int main() {
    int mat[M][N] = {
        {4, 7, 1, 6},
        {5, 7, 3, 9},
        {3, 2, 1, 2},
        {7, 1, 6, 3}
    };
    int cost = 25;

    cout << "Matrix:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << "Target cost: " << cost << endl << endl;

    // Plain recursion
    cout << "recursion : " << countPaths(mat, 0, 0, cost) << " path(s)" << endl;

    // Memoization
    vector<vector<vector<int>>> memo(M, vector<vector<int>>(N, vector<int>(cost + 1, -1)));
    cout << "Memoization     : " << countPathsMemo(mat, 0, 0, cost, memo) << " path(s)" << endl;

    // Show the actual paths
    cout << endl << "Paths with cost " << cost << ":" << endl;
    printPaths(mat, 0, 0, cost, "");

    return 0;
}