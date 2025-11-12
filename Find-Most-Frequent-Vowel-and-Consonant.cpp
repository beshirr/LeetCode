class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (auto i : s) {
            if (freq[i]) freq[i]++;
            else freq[i] = 1;
        }
        int maxV = 0, maxC = 0;
        for (auto i : freq) {
            if (isVowel(i.first)) maxV = max(i.second, maxV);
            else maxC = max(i.second, maxC);
        }
        return maxV + maxC;
    }
};