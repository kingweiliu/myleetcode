#include <vector>
using std::vector;


class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0;
        int j = nums.size();
        while (i < j) {
            while (i < j && (nums[i] % 2 == 1)) {
                i++;
            }
            while (j >= i && (nums[j] % 2 ==0)) {
                j--;
            }
            if (i<j) {
                int v = nums[i];
                nums[i++] = nums[j];
                nums[j--] = v;
            }

        }        
    }
};

