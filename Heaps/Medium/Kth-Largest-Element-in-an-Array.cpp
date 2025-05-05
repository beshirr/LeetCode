class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapfy(nums);
        int heapSize = nums.size();
        for (int i = 0; i < k - 1; ++i) {
            swap(nums[0], nums[heapSize-1]);
            --heapSize;
            downheap(nums, 0, heapSize);
        }

        return nums[0];
    }

    void heapfy(vector<int>& nums) {
        for (int i = nums.size() / 2; i >= 0; i--) {
            downheap(nums, i, nums.size());
        }
    }

    void downheap(vector<int>& nums, int index, int heapSize) {
        int max = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < heapSize && nums[left] > nums[max]) {
            max = left;
        } 
        if (right < heapSize && nums[right] > nums[max]) {
            max = right;
        }

        if (max != index) {
            swap(nums[max], nums[index]);
            downheap(nums, max, heapSize);
        }
    }
};