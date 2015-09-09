#include <string>
#include <iostream>
using std::string;

/*

问题一: 不知道ZigZag是什么形状的
问题二：第一行的处理上，重点还是临界的处理上

*/
class Solution {
public:
    string convert(string s, int numRows) {
        string result = "" ;
        int gap = numRows * 2 - 2;
        if (numRows == 1) {
            gap = 1;
        }

        for (int i = 0; i < numRows; ++i) {
            int j = i; 
            int slash = gap - j;
            
            while (j < s.length()) {
                result += s[j];
                if (i != 0 && (i != (numRows-1)) && slash < s.length()) {
                    result += s[slash];
                }
                j += gap;
                slash += gap;
            }
        }    
        return result;
    }
};


int main() {
    Solution s;
    std::string input = "PAYPALISHIRING";
    std::cout << s.convert(input, 3) << std::endl;
    input = "ABC";
    std::cout << s.convert(input, 2) << std::endl;
    input = "ABCD";
    std::cout << s.convert(input, 1) << std::endl;
    string input1 = "AB";
    std::cout << s.convert(input1, 3) << std::endl;
    std::cout << (-1)/2 << std::endl;
}
