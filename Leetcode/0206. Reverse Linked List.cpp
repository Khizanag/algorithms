/* Reverse a singly linked list. */

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; // base case
        
        ListNode* revNode = reverseList(head->next); // rec
        head->next->next = head;
        head->next = NULL;
        
        return revNode;
    }
};