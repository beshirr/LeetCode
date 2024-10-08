class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid+1]) return nums[mid + 1];
            else if (mid > start && nums[mid] < nums[mid-1]) return nums[mid];

            else if (nums[mid] <= nums[start]) end = mid - 1;
            else start = mid + 1;
        }
        return nums[0]; 
    }
}