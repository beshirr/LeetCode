class Solution {
    public int findPeakElement(int[] nums) {
        int start = 0, end = nums.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == start) {
                if (nums[start] > nums[end]) return start;
                return end;
            }
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] < nums[mid+1]) start = mid + 1;
            else end = mid - 1;
            
        }
        return -1;
    }
}