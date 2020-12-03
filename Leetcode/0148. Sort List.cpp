/*Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?*/

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
    ListNode* sortList(ListNode* head) {
        for(ListNode * node = head; node != NULL; node = node->next)
        {
            ListNode * minNode = node;
            ListNode * toComp;
            for(toComp = node; toComp != NULL; toComp = toComp->next)
            {
                if(toComp->val < minNode->val)
                {
                    minNode = toComp;
                }
            }
            int tmp = node->val;
            node->val = minNode->val;
            minNode->val = tmp;
        }
        return head;
    }
};