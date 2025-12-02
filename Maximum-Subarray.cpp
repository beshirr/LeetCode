1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxArr = INT_MIN;
5        int sum = 0;
6
7        for (int i = 0; i < nums.size(); i++) {
8            sum += nums[i];
9            maxArr = max(maxArr, sum);
10
11            if (sum < 0) sum = 0;
12        }
13        return maxArr;
14    }
15};