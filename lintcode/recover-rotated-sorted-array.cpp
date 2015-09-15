#include <iostream>
#include <vector>
using std::vector;

class Solution {
	
	void reverse(vector<int>& nums, int start, int end) {
		for (int i= start, j = end-1; i < j; ++i, --j) {
			int n = nums[i];
			nums[i] = nums[j];
			nums[j] = n;
		}
	}

public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
		if (nums.size() <=1)
			return;
		int i = 1;
		while (i < nums.size() && nums[i] >= nums[i-1])
			i++;
		
		std::cout << i << std::endl;
		reverse(nums, 0, i);
		reverse(nums, i, nums.size());
		reverse(nums,0, nums.size());		
    }
};


int main() {
	int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<int> v(a, a+ 21);
	Solution s;
	s.recoverRotatedSortedArray(v);
}