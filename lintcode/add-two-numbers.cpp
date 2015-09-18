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
		ListNode * prior = currentNode;
		while (l1 && l2) {
			int sum  = carry + l1->val + l2->val;
			if (sum > 9) carry = 1;
			else carry = 0;
			currentNode->val = sum % 10;				
			l1 = l1->next;
			l2 = l2->next;
			prior = currentNode;
			currentNode = currentNode->next ;
		}
		if (l2) {
			prior->next = l2;
			currentNode = l2;
		}
		
		while (currentNode) {
			int sum  = carry + currentNode->val;
			if (sum > 9) carry = 1;
			else carry = 0;
			currentNode->val = sum % 10;
            prior = currentNode;
			currentNode = currentNode->next;
		}
		if (carry) {
			ListNode* node = new ListNode(carry);
			prior->next = node;			
		}
		
		return newList;
    }
};