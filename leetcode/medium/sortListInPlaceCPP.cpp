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

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        auto head = res;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        head->next = (l1) ? l1 : l2;

        return res->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;
        auto l1 = sortList(head);
        auto l2 = sortList(slow);
        
        return merge(l1, l2);
    }
};