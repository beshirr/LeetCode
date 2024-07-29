/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        // The approach is to do the binary search twice after finding the peak value
        // as the order of the array changes around the peak value
        // we do it for the first half then the other half.
        Map<Integer, Integer> cache = new HashMap<>();
        int peak = mountain(mountainArr, cache);
        int firstHalf = oabs(mountainArr, target, 0, peak, cache);
        int secondHalf = oabs(mountainArr, target, peak, mountainArr.length()-1, cache);
        if (firstHalf != -1 && secondHalf != -1) 
            return Math.min(firstHalf, secondHalf);
        else return Math.max(firstHalf, secondHalf);
    }
    
    private int get(MountainArray mountainArr, int index, Map<Integer, Integer> cache) {
    if (!cache.containsKey(index)) {
        cache.put(index, mountainArr.get(index));
    }
    return cache.get(index);
}
    public int oabs(MountainArray mountainArr, int target, int start, int end, Map<Integer, Integer> cache) {
        boolean isAsc;
        isAsc = mountainArr.get(start) < mountainArr.get(end);

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = get(mountainArr, mid, cache);
            if (target == midValue) return mid;

            if (isAsc) {
                if (target < midValue) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target > midValue) end = mid - 1;
                else start = mid + 1;
            }
        }
        return -1;
    }

    public int mountain(MountainArray mountainArr, Map<Integer, Integer> cache) {
        int start = 0, end = mountainArr.length() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (mid == start) {
                if (get(mountainArr, start, cache) > get(mountainArr, end, cache)) return start;
                return end;
            };
            if (get(mountainArr, mid, cache) > get(mountainArr, mid - 1, cache) && get(mountainArr, mid, cache) > get(mountainArr, mid + 1, cache))
                return mid;
            else if (get(mountainArr, mid, cache) < get(mountainArr, mid + 1, cache)) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
}