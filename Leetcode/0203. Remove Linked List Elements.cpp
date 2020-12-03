/* Remove all elements from a linked list of integers that have value val. */

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        while(head != NULL and head->val == val)
            head = head->next;
        
        for(ListNode *node = head; node != NULL and node->next != NULL; node=node->next)
        while(node != NULL and node->next != NULL)
        {
            if(node->next->val == val)
            {
                node->next = node->next->next;
            } else
                node = node->next;
        }
            
        return head;
    }
};