class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        register = [0, 0]
        
        for i in bills:
            if i == 5:
                register[0] += 1
            elif i == 10:
                register[1] += 1
                if register[0] < 1:
                    return False
                register[0] -= 1
            elif i == 20:
                if register[0] >= 1 and register[1] >= 1:
                    register[0] -= 1
                    register[1] -= 1
                elif register[0] >= 3:
                    register[0] -= 3
                else:
                    return False
        
        return True