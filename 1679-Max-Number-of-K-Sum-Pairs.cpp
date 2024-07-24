class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int counter = 0; 
        int i = 0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                counter ++;
                i++, j--;
            }
            else if (nums[i] + nums[j] > k) j--;
            else i++; 
        }
        return counter;
    }
};