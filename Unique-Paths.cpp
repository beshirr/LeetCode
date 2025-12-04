1class Solution {
2public:
3    int dp[101][101]{{}};
4    int uniquePaths(int m, int n) {
5        return path(m, n, 0, 0);
6    }
7
8    int path(int m, int n, int i, int j) {
9        if (i == m-1 && j == n-1) {
10            return 1;
11        }
12        if (i >= m || j >= n) return 0;
13        if (dp[i][j]) return dp[i][j];
14        dp[i][j] = path(m, n, i, j+1) + path(m, n, i+1, j);
15        return dp[i][j];
16    }
17};