/* Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? */

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
	int find_linked_list_length(ListNode * head)
	{
		int len = 0;
		while(head != NULL)
		{
			len += 1;
			head = head->next;
		}
		return len;
	}
	
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */

	vector<int> v;
	Solution(ListNode* head) {
		while(head != NULL)
		{
			v.push_back(head->val);
			head = head->next;
		}
	}
	
	/** Returns a random node's value. */
	int getRandom() {
		int random_index = rand() % v.size();
		return v[random_index];
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */