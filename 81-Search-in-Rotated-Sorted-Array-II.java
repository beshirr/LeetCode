class Solution {
    public boolean search(int[] nums, int target) {
        int rotationPt = pivotWithDuplicates(nums);

        if (rotationPt == -1)
            return oabs(nums, target, 0, nums.length-1);
        if (nums[rotationPt] == target)
            return true;

        return oabs(nums, target, 0, rotationPt) ||
                oabs(nums, target, rotationPt+1, nums.length-1);
    }

    public int pivotWithDuplicates(int[] nums) {
        int start = 0, end = nums.length-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid+1]) return mid;
            else if (mid > start && nums[mid] < nums[mid-1]) return mid-1;

            if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                // checking for duplicates
                if (start < end && nums[start] > nums[start+1]) return start;
                start++;
                if (end > start && nums[end] < nums[end-1]) return end - 1;
                end--;
            }

            else if (nums[mid] > nums[start] || (nums[start] == nums[mid] && nums[mid] > nums[end])) {
                start = mid + 1;
            } else end = mid - 1;
        }
        return -1;
    }

    public boolean oabs(int[] arr, int target, int start, int end) {
        boolean isAsc;
        isAsc = arr[start] < arr[end];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) return true;

            if (isAsc) {
                if (target < arr[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target > arr[mid]) end = mid - 1;
                else start = mid + 1;
            }
        }
        return false;
    }
}