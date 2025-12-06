1class Solution {
2public:
3    int dp[46]{};
4    int climbStairs(int n) {
5        if (n == 1 || n == 0) return 1;
6        if (dp[n]) return dp[n];
7        dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
8        return dp[n];
9    }
10};