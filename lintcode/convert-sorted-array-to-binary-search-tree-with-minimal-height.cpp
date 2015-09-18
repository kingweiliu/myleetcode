/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
	
	TreeNode* arrayToBst(vector<int> &A, int start, int end) {
		if (start == end) {
			return new TreeNode(A[start]);
		} else if (start > end) {
			return NULL;
		}
		int m = (start + end) / 2;
		TreeNode* mNode = new TreeNode(A[m]);
		mNode->left = arrayToBst(A, start, m-1);
		mNode->right = arrayToBst(A, m+1, end);	
		return mNode;
	}
	
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
		return  arrayToBst(A, 0, A.size() - 1);
		
    }
};
