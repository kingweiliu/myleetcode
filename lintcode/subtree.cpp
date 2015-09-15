#include <iostream>
// * Definition of TreeNode:
  class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };

 
// 应该主动性想出分治法
class Solution {
private:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        
        if (t1 == NULL && t2 == NULL)
            return true;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1->val != t2->val)
            return false;
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (isSameTree(T1, T2))
            return true;
		if (T1 && (isSubtree(T1->left, T2) || isSubtree(T1->right, T2)))
				return true;
		return false;
		
		std::cout << T1->val << std::endl;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
};

int main() {
		TreeNode* t4 = new TreeNode(4);
		TreeNode* t3 = new TreeNode(3);
		t3->left = t4;
		TreeNode* t1 = new TreeNode(1);
		t1->left = new TreeNode(2);
		t1->right = t3;
		
		TreeNode* tt2 = new TreeNode(3);
		tt2->left = new TreeNode(4);
		
		Solution s;
		std::cout << s.isSubtree(t1, tt2);
}


