/*Sort a linked list using insertion sort.*/

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
    ListNode* insertionSortList(ListNode* head) {
        for(ListNode* node = head; node != NULL; node = node->next)
        {
            ListNode* found = NULL;
            for(ListNode* iiNode = node; iiNode != NULL;  iiNode = iiNode->next)
            {
                if(found == NULL || iiNode->val < found->val)
                    found = iiNode;
            }
            if(found && found != node) // swap
            {
                int tmp = found->val;
                found->val = node->val;
                node->val = tmp;
            }
        }
        return head;
    }
};