//https://leetcode.com/problems/unique-paths/
class Solution {
public:
        int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> matrixBoard(m, vector<int>(n, 0));
        for (int i{}; i < n; i++) {
            matrixBoard[0][i] = 1;
        }
        for (int i{}; i < m; i++) {
            matrixBoard[i][0] = 1;
        }
        // You can get to (i,j) via (i - 1,j) and (i, j - 1);
        for (int i{1}; i < m; i++) {
            for (int j{1}; j < n; j++) {
                matrixBoard[i][j] = matrixBoard[i-1][j] + matrixBoard[i][j-1];
            }
        }
        return matrixBoard[m - 1][n - 1];
    }
};