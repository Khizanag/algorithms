/* Given a sorted linked list, delete all duplicates such that each element appear only once. */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        auto cur = head;
        while(cur->next != NULL)
        {
            if(cur->val == cur->next->val)
                cur->next = cur->next->next;
            else 
                cur = cur->next;
        }
        return head;
    }
};