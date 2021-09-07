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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        if(tempA == NULL || tempB == NULL) return NULL;
        if(tempA == tempB) return tempA;
        //Exists the loop if the two are equal
        while(tempA != tempB) {
            //moves along the list
            tempA = tempA->next;
            tempB = tempB->next;
            //if the two are equal then returns the answer
            if(tempA == tempB) return tempA;
            //If one list reaches the end before the other, then reset it to point to the other list this way they will be equidistant from the intersection and meet there.
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
        }

        return tempA;
    }
};
