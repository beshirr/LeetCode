class Solution {
    public int search(int[] nums, int target) {
        int rotationPt = getRotationPoint(nums);

        if (rotationPt == -1)
            return oabs(nums, target, 0, nums.length-1);
        if (nums[rotationPt] == target)
            return rotationPt;

        return Math.max(oabs(nums, target, 0, rotationPt),
                oabs(nums, target, rotationPt+1, nums.length-1));
    }

    public int getRotationPoint(int[] nums) {
        int start = 0, end = nums.length-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid+1]) return mid;
            else if (mid > start && nums[mid] < nums[mid-1]) return mid-1;

            else if (nums[mid] <= nums[start]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }

    public int oabs(int[] arr, int target, int start, int end) {
        boolean isAsc;
        isAsc = arr[start] < arr[end];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) return mid;

            if (isAsc) {
                if (target < arr[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target > arr[mid]) end = mid - 1;
                else start = mid + 1;
            }
        }
        return -1;
    }
}