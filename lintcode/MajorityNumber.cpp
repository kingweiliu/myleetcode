#include <iostream>
#include <vector>
using std::vector;

class Solution {
private:
    int findMiddle(vector<int>& nums, int r, int l, int pos) {
        if (r==l)
            return nums[r];
        int n = nums[r];
        int i = r + 1, j = l;
        while (i<j) {
            while (i < j && nums[i] <= n) i++;
            while (i < j && nums[j] > n) j--;
            if (i < j) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
		nums[r] = nums[j];
		nums[j] = nums[r];
				
		std::cout << "r:"<< r <<", l:"<<l <<", i:" << i << ", pos:" << pos <<std::endl;
        if (i > pos) {
            return findMiddle(nums, r, i-1, pos);
        } else if (i < pos) {
            return findMiddle(nums, i+1, l, pos);
        } else {
            return nums[i];
        }
    }
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        return findMiddle(nums, 0, nums.size()-1, nums.size()/2);
        
    }
};

int main() {
    Solution s;
    int a[] = {111,222,111,111,222,343,90,90,111,111,111,0,111};
    vector<int> v(a, a+13);
    std::cout << s.majorityNumber(v);
    
}
