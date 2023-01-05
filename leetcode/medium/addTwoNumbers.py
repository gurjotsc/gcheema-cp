# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        res = ListNode()
        head = res
        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            ans = val1+val2+carry

            carry, ans = divmod(ans, 10)
            
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

            head.next = ListNode(ans)
            head = head.next

        if carry:
            head.next = ListNode(1)

        return res.next