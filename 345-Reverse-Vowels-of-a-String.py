class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a','A','E', 'e', 'i', 'I','o','O','u', 'U']
        wordvowel = []
        ans = \\

        for l in s:
            if l in vowels:
                wordvowel.append(l)

        wordvowel = wordvowel[::-1]

        for l in s:
            
            if l in vowels:
               l = wordvowel[0]
               wordvowel.remove(wordvowel[0]) 
            ans += l

        return ans


        

        
        