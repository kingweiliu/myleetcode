#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {

public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        if (A.size() == 0)
            return 0;
            
        // Write your code here
		vector<int> B = A;
		sort(B.begin(), B.end());
		
		long long result = 0;
		vector<long long> factorial(A.size() + 1);
		factorial[0] = 1;
		factorial[1] = 1;
		for (int i = 2;i<A.size() + 1; ++i) {
		    factorial[i] = factorial[i-1] * i;
		}
		
		for (int i=0; i < A.size(); ++i) {
		    int index = find(B.begin(), B.end(), A[i]) - B.begin();
		    result += index * factorial[A.size()-1 - i];
		    B.erase(B.begin() + index);
		}
		
		
		return result+1;
    }
};
