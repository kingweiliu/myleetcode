#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};




/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
private:
    SegmentTreeNode * build_gap(vector<int>& A, int l, int r) {
        if (l > r) 
            return NULL;
        else if (l == r) {
            return new SegmentTreeNode(l, r, A[r]);
        }
        int mx = *std::max_element(A.begin() + l, A.begin() + r + 1);
        SegmentTreeNode* node = new SegmentTreeNode(l, r, mx);
        node->left = build_gap(A, l, (l+r)/2);
        node->right = build_gap(A, (l+r)/2 + 1, r);
    }

public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        return build_gap(A, 0, A.size()-1); 
    }
};


void printnode(SegmentTreeNode *node) {
    if (!node) 
        return;
    std::cout << "[" << node->start <<","<<node->end<<"]"<< node->max <<std::endl;
    printnode(node->left);
    printnode(node->right);
}


int main() {
    Solution s;
    int a[] = {3, 2, 1, 4};
    vector<int> v(a, a+4);
    SegmentTreeNode* node = s.build(v);
    std::cout << node->max << std::endl;    
    printnode(node);

}
