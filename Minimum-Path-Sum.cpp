1class Solution {
2public:
3    int dp[201][201]{{}};
4    int minPathSum(vector<vector<int>>& grid) {
5        return pathSum(grid, 0, 0);
6    }
7
8    int pathSum(vector<vector<int>>& grid, int i, int j) {
9        if (i == grid.size()-1 && j == grid[0].size()-1) {
10            return grid[i][j];
11        }
12        if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;
13        if (dp[i][j]) return dp[i][j];
14        dp[i][j] = grid[i][j] + min(pathSum(grid, i, j+1), pathSum(grid, i+1, j));
15        return dp[i][j];
16    }
17};