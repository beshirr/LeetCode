class Solution {
    public int mySqrt(int x) {
        long start = 1, end = x, mid = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (mid * mid == x) return (int) mid;
            else if (mid * mid > x) end = mid - 1;
            else start = mid + 1;
        }
        if (mid * mid > x) return (int) mid - 1;
        return (int) mid;
    }
}