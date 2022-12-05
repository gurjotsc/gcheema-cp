class Solution:
    def compress(self, chars: List[str]) -> int:
        i = cnt = prev = 0
        while i < len(chars):
            if chars[i] == chars[prev]:
                cnt += 1
                i += 1
            else:
                if cnt == 1:
                    prev = i
                    i += 1
                else:
                    del chars[prev+1:i]
                    i = prev
                    chars[prev+1:prev+1] = list(str(cnt))
                    i += len(list(str(cnt))) + 1
                    cnt = 1
                    prev = i
                    i += 1
        
        if cnt != 1:
            del chars[prev+1:]
            chars[prev+1:prev+1] = list(str(cnt))
        
        return len(chars)