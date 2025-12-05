1class Solution {
2public:
3    int dp[101][101]{{}};
4    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
5        return path(obstacleGrid, 0, 0);
6    }
7
8    int path(vector<vector<int>>& obstacleGrid, int i, int j) {
9        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size()) return 0;
10        if (obstacleGrid[i][j] == 1) return 0;
11
12        if (i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) {
13            return 1;
14        }
15        
16        if (dp[i][j]) return dp[i][j];
17        dp[i][j] = path(obstacleGrid, i, j+1) + path(obstacleGrid, i+1, j);
18        return dp[i][j];
19    }
20};