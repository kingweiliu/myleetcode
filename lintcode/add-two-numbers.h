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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
	ListNode *addLists(ListNode *l1, ListNode *l2) {		
		int carry = 0;
		ListNode* newList = l1 ? l1 : l2;
		ListNode* currentNode = newList;
		while (l1 && l2) {
			int sum  = carry + l1->val + l2->val;
			if (sum > 9) carry = 1;
			else carry = 0;
			currentNode->val = sum % 10;				
			l1 = l1->next;
			l2 = l2->next;
			if (currentNode->next)
			    currentNode = currentNode->next ;
		}
		if (l2) 
			currentNode->next = l2;
		if (currentNode)
		    currentNode = currentNode->next;
		while (currentNode) {
			int sum  = carry + currentNode->val;
			if (sum > 9) carry = 1;
			else carry = 0;
			currentNode->val = sum % 10;
			if (!currentNode->next)
			    break;
			currentNode = currentNode->next;
		}
		if (carry) {
			ListNode* node = new ListNode(carry);
			currentNode->next = node;			
		}
		return newList;
    }
};