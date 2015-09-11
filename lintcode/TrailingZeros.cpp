#include <iostream>

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long result = 0;
		long long m = n / 5;
		while (m) {
			result += m;
			m /= 5;
		}
		return result;
    }
};

int main() {
	Solution s;
	std::cout << s.trailingZeros(1000) ;
}