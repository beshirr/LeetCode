1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        vector<int> n; 
5        for (int i = 0; i < nums.size(); ++i) {
6            if (nums[i] == val) {
7                continue;
8            }
9            n.push_back(nums[i]);
10        }
11
12        for (int i = 0; i < n.size(); ++i) {
13            nums[i] = n[i];
14        }
15        return n.size();
16    }
17};