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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum   = l1->val + l2->val;
        int toAdd = sum % 10;
        int rem   = sum / 10;

        ListNode * currNode = new ListNode(toAdd);
        ListNode * result = currNode;
        
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
        
        while(l1 != NULL || l2 != NULL)
        {
            sum   = ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + rem;
            toAdd = sum % 10;
            rem   = sum / 10;
            
            ListNode * newNode = new ListNode(toAdd);
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;

            currNode->next = newNode;
            currNode = newNode; 

        }
        
        if(rem != 0)
        {
            ListNode * newNode = new ListNode(rem);
            currNode->next = newNode;
        }
        
        return result;
    }
};