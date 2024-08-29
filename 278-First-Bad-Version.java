/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int start = 1, end = n, mid = 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (isBadVersion(mid)) end = mid -1;
            else start = mid + 1;
        }
        if (mid == start) return mid;
        else return mid + 1;
    }
}