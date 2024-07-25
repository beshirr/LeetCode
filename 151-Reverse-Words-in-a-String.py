class Solution:
    def reverseWords(self, s: str) -> str:
        ans = \\
        words = s.split()
        words = words[::-1]
        
        for w in range(0, len(words) - 1):
            ans += words[w]
            ans += \ \

        ans += words[len(words) - 1]
        return ans

        