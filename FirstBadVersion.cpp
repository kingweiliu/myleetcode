#include <iostream>
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:

    int findBadVersion(int l, int r) {
	std::cout << "input:" << l << ", " << r << std::endl;
        if (l >= r) {
            return r;
        }
        /****************/
        //  此处注意整数越界
        int mid = l / 2 + r / 2;  
        /*************/
        if (isBadVersion(mid)) {
	    std::cout << l << ", " << mid << std::endl;
            return findBadVersion(l, mid);
        } else {
            return findBadVersion(mid + 1, r);
	    std::cout << mid << ", " << r << std::endl;
        }
    }
    
public:
    
    int firstBadVersion(int n) {
        return findBadVersion(0, n);
    }
};


bool isBadVersion(int version) {
	return version >= 1702766719;
}

int main() {
	Solution s; 
	std::cout << s.firstBadVersion(2126753390) << std::endl;
}
