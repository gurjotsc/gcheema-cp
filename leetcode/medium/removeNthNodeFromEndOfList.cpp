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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        for(auto p = head; p != NULL; ++sz) p = p->next;

        auto p = head, prev = head;
        for(int i = 0; i < sz-n; ++i) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        return (!(sz-n)) ? head->next : head;
    }
};