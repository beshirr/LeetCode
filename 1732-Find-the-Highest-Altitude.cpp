class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> pref(n + 1);
        pref[0] = 0;
        int maximum = pref[0];
        
        for (int i = 1; i < pref.size(); ++i) {
            pref[i] = gain[i - 1] + pref[i - 1];
            maximum = max(maximum, pref[i]);
        }
        return maximum;
    }
};