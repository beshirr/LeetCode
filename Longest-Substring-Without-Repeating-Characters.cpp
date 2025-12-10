1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, bool> mp;
5        int ans = 0;
6        int l = 0;
7        for (int r = 0; r < s.length(); ++r) {
8            while (mp[s[r]]) {
9                mp[s[l]] = false;
10                l++;
11            } 
12            mp[s[r]] = true;
13            ans = max(r - l + 1, ans);
14        }
15        return ans;
16    }
17};