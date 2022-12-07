class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        done = 0
        for i, [a,t] in enumerate(customers):
            if a >= done:
                done = a+t
                customers[i][0] = t
            else:
                customers[i][0] = t + (done-a)
                done += t
        return sum([wait for wait, t in customers])/len(customers)