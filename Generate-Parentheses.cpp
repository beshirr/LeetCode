1class Solution {
2public:
3    vector<string> generateParenthesis(int n) {
4        vector<string> ans;
5        generate(n, n, "", ans);
6        return ans;
7    }
8
9    void generate(int o, int c, string&& s, vector<string>& ans) {
10        if (o == 0 && c == 0) {
11            ans.push_back(s);
12            return;
13        }
14        if (o > 0) {
15            s.push_back('(');
16            generate(o - 1, c, std::move(s), ans);
17            s.pop_back();
18        }
19        if (o < c) {
20            s.push_back(')');
21            generate(o, c - 1, std::move(s), ans);
22            s.pop_back();
23        }
24    }
25};