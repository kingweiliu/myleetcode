#include <vector>
using std::vector;

class Solution {
private:
	int findFirstIndex(vector<int> &array, int r, int l, int target) {
		if (r == l) {
			if (target == array[r])
				return r;
			return -1;
		}
		
		int mid = (r + l) / 2;
		if (array[mid] >= target) {
			return findFirstIndex(array, r, mid, target);
		} else {
			return findFirstIndex(array, mid + 1, l, target);
		}
	}
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {		
        // write your code here
		return findFirstIndex(array, 0, array.size() - 1, target);
        return -1;
    }
};
