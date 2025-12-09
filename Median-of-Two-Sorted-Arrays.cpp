1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0; int j = 0; int k = 0;
5        vector<int> arr(nums2.size()+nums1.size());
6        while (i < nums1.size() && j < nums2.size()) {
7            if (nums1[i] <= nums2[j]) {
8                arr[k] = nums1[i];
9                i++;
10            }
11            else {
12                arr[k] = nums2[j];
13                j++;
14            }
15            k++;
16        }
17
18        while (i < nums1.size()) {
19            arr[k] = nums1[i];
20            i++;
21            k++;
22        }
23
24        while (j < nums2.size()) {
25            arr[k] = nums2[j];
26            j++;
27            k++;
28        }
29
30        if (arr.size()%2 == 1) return (double) arr[arr.size()/2];
31        return (arr[(arr.size()-1)/2] + arr[((arr.size()-1)/2)+1]) / 2.0;
32    }
33};