class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        c = Counter(letters)
        n = len(words)
        res = 0
        for i in range(0, 2**n):
            cnt = defaultdict(int)
            for j in range(n):
                if(i & 1): 
                    for x in words[j]:
                        cnt[x] += 1
                i >>= 1

            flag = False
            curr = 0
            for k in cnt:
                if(cnt[k] > c[k]): flag = True
                curr += (cnt[k] * score[ord(k) - ord('a')])
            res = max(res, curr) if not flag else res
                
        return res