/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p) {
            while (p->next && p->next->val == p->val) {
                auto tmp = p->next->next;
                p->next = tmp;
            }
            p = p->next;
        }
        return head;
    }
};