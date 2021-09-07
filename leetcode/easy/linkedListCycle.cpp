/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* walk = head;
        ListNode* run = head;
        //Tortise and Hare algorithm. They have to eventually meet up if there is a cycle.
        while(run->next != NULL && run->next->next != NULL) {
            walk = walk->next;
            run = run->next->next;
            if(walk == run) return true;
        }
        return false;
    }
};
