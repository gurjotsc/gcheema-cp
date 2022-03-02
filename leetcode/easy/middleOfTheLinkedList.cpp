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
    ListNode* middleNode(ListNode* head) {
        auto temp = head;
        int count = 0;
        while(temp) {
            ++count;
            temp = temp->next;
        }
        count = (count/2) + 1;
        auto prev = head;
        while(count--) {
            prev = head;
            head = head->next;
        }
        return prev;
    }
};