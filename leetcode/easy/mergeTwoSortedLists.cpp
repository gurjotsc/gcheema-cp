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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //Create a linked list to return and a pointer to it
        ListNode merged;
        ListNode* p = &merged;
        //Iterate while both lists exitst
        while(l1 && l2) {
            //Point p to l1 if its greater and move l1 to the next node because we no longer need to worry about the origonal node (this is because the lists are sorted so no other value after l1 can be less than l2)
            if(l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            //Same thing but for the l2 condition
            else {
                p->next = l2;
                l2 = l2->next;
            }
            //Iterate p to the next node
            p = p->next;
        }

        //If any list still has values left after the other has reached the end in the loop then set p to the reaminder of the other list
        //Read as assign p->next with l1 if(l1) else assign with l2
        //More genrally, "if condition is true then evaluate to result1 else result2"
        p->next = l1 ? l1 : l2;

        //Return the first node
        return merged.next;
    }
};
