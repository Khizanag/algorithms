/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it. */

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        set< pair<int, ListNode*>> st;
        for(int i = 0; i < lists.size(); i+=1)
            if(lists[i] != NULL)
                st.insert({lists[i]->val, lists[i]});
        
        ListNode *root = new ListNode(INT_MIN);
        ListNode *sortedListLastNode = root;
        while(st.size() > 0)
        {
            auto pr = *st.begin(); st.erase(pr);
            sortedListLastNode->next = pr.second;
            sortedListLastNode = sortedListLastNode->next;
            
            if(pr.second->next != NULL)
                st.insert({pr.second->next->val, pr.second->next});
        }
        
        return root->next;
    }
};