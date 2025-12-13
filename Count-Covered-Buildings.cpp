1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
4        vector<int> max_r(n+1, 0); vector<int> min_r(n+1, n+1);
5        vector<int> max_c(n+1, 0); vector<int> min_c(n+1, n+1);
6
7        for (auto& b : buildings) {
8            max_c[b[0]] = max(max_c[b[0]], b[1]);
9            max_r[b[1]] = max(max_r[b[1]], b[0]);
10            min_c[b[0]] = min(min_c[b[0]], b[1]);
11            min_r[b[1]] = min(min_r[b[1]], b[0]);
12        }
13
14        int ans = 0;
15        for (auto& b: buildings) {
16            if (b[0] > min_r[b[1]] && b[0] < max_r[b[1]] && b[1] > min_c[b[0]] 
17                && b[1] < max_c[b[0]]) ans++;
18        }
19        return ans;
20    }
21};