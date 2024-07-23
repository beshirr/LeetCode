class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        int start = search(nums, target, true);
        int end = search(nums, target, false);

        ans[0] = start;
        ans[1] = end;

        return ans;
    }   

    int search(vector<int>& nums, int target, bool isFirst) {
        // Applying the binary search twice
        // First time to determine the first position
        // Second time for the last position

        // determine it using the boolean value of isFirst 
        
        // assuming the default value for ans is -1, ans might be the first position or the last one (determined by the isFirst)
        int ans = -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                ans = mid;
                if (isFirst) end = mid - 1;
                else start = mid + 1;
            }
            else if (target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        } 
        return ans;
    }
};