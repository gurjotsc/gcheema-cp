class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        n = len(tickets)
        res = 0
        for i in range(k+1): 
            tickets[i] -= 1
            res += 1
        tickets = tickets[k+1:]+tickets[:k+1]
        for i in tickets:
            res += min(tickets[-1], i)
        return res