class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0, end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == start) {
                if (arr[start] > arr[end]) return start;
                return end;
            };
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if (arr[mid] < arr[mid+1]) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
}