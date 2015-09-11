#include <iostream>

// ±ﬂΩÁ÷µ
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
		if (!source || !target)
			return -1;
		if (*source == 0 && *target == 0)
			return 0;

        // write your code here
		const char* s = source;
		const char* t = target;
		const char* ts;
		for (; *s != 0; ++s) {
			t = target;
			ts = s;
			while (*t && (*ts++ == *t++ ));
			if (!*t)
				return s-source;
		}		
        return -1;
    }
};

int main() {
	Solution s;
	std::cout << s.strStr("abcdabcdefg", "bcd");
}