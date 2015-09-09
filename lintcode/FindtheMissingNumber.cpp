#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != -1) {
                int x = nums[i];
                nums[i] = nums[x];
                nums[x] = x;
            }
        }
        
        for (int i=0; i< nums.size(); ++i) {
            if (nums[i] == -1) {
                return i;
            }
        }
        
    }
};

int main() {
    Solution s;
    int a[] = {3, 1, 0};
    vector<int> v(a, a+3);
    std::cout << s.findMissing(v) <<std::endl;
}
