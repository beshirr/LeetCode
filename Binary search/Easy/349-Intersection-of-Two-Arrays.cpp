class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numbers(nums1.begin(), nums1.end());
        unordered_set<int> intersection;

        for (int number : nums2) {
            if (numbers.find(number) != numbers.end()) {
                intersection.insert(number);
            }
        }

        return vector<int> (intersection.begin(), intersection.end());
    }
};