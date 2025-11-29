1class Solution {
2public:
3    int dp[20]{};
4    int numTrees(int n) {
5        if (n <= 1) return 1;
6
7        if (dp[n]) return dp[n];
8        for (int i = 1; i <= n; i++) dp[n] += numTrees(i-1) * numTrees(n-i);
9        return dp[n];
10    }
11};