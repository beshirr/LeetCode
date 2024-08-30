class Solution {
    public int findKthPositive(int[] arr, int k) {
        int counter = 0, number = 1;
        while (counter != k) {
            if (!binary_search(arr, number)) counter++;
            number++;
        }
        return number-1;
    }

    public boolean binary_search(int[] arr, int target) {
        int start = 0, end = arr.length-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
}