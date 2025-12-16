1class Solution {
2public:
3    bool canPartition(vector<int>& nums) {
4        int sum = 0, n = nums.size();
5        for (int i = 0; i < n; i++) {
6            sum += nums[i];
7        }
8        if (sum % 2 != 0)
9            return false;
10
11        bitset<10001> dp(1);
12        for (auto i : nums) {
13            dp |= dp << i;
14            if (dp[sum / 2])
15                return true;
16        }
17        return dp[sum / 2];
18    }
19};