#include <string.h>

#include <iostream>

// null 输入

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (string == NULL) 
            return 0;
        // Write your code here
        int space_count = 0;
        for (int i=0; i< length; i++) {
            if (string[i] == ' ')
                space_count ++;
        }
        int i = length;
        int j = length + space_count * 2;
        int len = j;
        std::cout << "len:" << length <<", space:" << space_count << ", tlen:" << j << std::endl;
        while (i >= 0) {
            if (string[i] == ' ') {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
                i--;
            } else
                string[j--] = string[i--];
        }        
        return len;
    }
};  


int main() {
    char str[100] = "Mr John Smith";
    Solution s;
    std::cout << s.replaceBlank(str, strlen(str))  << ":"<< str<< std::endl;
}
