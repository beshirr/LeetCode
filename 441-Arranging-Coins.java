class Solution {
    public int arrangeCoins(int n) {
        long start = 1, end = n, mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((mid * (mid+1) / 2) == n) return (int) mid;
            else if ((mid * (mid+1) / 2) > n) end = mid - 1;
            else start = mid + 1;
        }
        if ((mid * (mid+1) / 2) > n) return (int) mid - 1;
        return (int) mid;
    }
}