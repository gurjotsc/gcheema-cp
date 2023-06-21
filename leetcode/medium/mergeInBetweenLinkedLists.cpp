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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt = 0;
        auto curr = list1;
        ListNode* temp = curr;
        while(cnt != a) {
            curr = curr->next;
            ++cnt;
            if(cnt != a)
                temp = curr;
        }

        for(int i = a; i <= b; ++i) {
            auto d = curr;
            curr = curr->next;
            delete d;
        }

        temp->next = list2;

        while(temp->next != NULL)
            temp = temp->next;
        temp->next = curr;
        return list1;
    }
};