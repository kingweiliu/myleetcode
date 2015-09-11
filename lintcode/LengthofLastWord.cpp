#include <string>

using std::string;

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
		int length = 0;
		bool start = false;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' '){
				start = false;
			} else if (start) {
				length ++;
			} else {
				start = true;
				length = 1;
			}				
		}
		return length;
    }
};


