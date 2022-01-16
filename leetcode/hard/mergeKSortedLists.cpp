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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        //see Merge Two Sorted Lists on leetcode 21
        ListNode merged;
        ListNode* p = &merged;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p ->next;
        }
        p->next = l1 ? l1 : l2;
        return merged.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(!k) return NULL;
        int interval = 1; //keeps track of what interval includes all non-empty indexes in lists as we combine lists.
        //For instance, the first iteration, we skip interval=1 indexes to fill, next iteration we skip interval=2 indicies, and then interval=4 indicies and so on
        //This while loop does the above.
        while(interval < k) {
            for(int i = 0; i + interval < k; i = i+interval*2) {
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }
            interval*=2;
        }
        //the res is stored in lists[0]
        return lists[0];        
    }
};