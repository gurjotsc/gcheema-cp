class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        s = set(words)  # removes duplicates
        for w in words:
            for i in range(1, len(w)):
                # remove all words that appear as suffixes of some word
                s.discard(w[i:])
        return sum([len(w)+1 for w in s])