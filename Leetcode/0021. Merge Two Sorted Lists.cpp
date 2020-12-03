/* Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists. */

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
        if(l1 == NULL and l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val) { swap(l1, l2); }

        ListNode * R  = l1;
        ListNode * n1 = l1->next;
        ListNode * n2 = l2;
        
        while(n1 != NULL and n2 != NULL)
        {
            if(n1->val > n2->val)
                swap(n1, n2);
            R->next = n1;
            R = R->next;
            n1 = n1->next;
        }
        
        if(n1 == NULL) swap(n1, n2);
        R->next = n1;
        
        return l1;
    }
};