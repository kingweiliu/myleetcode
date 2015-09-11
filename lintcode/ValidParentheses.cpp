#include <map>
#include <stack>
#include <string>
using std::string;
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code heres
		std::stack<char> ps;
        std::map<char, char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
		for (int i= 0; i<s.length(); ++i) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    ps.push(s[i]);
                    break;
                case ')':
                case '}':
                case ']':
                    
                    if (ps.top() != mp[s[i]])
                        return false;
                    ps.pop();
                    break;
                default:
                    return false;
            }
        }
        return ps.size() == 0;
    }
};
