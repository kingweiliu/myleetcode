#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int max_len = 0;
        vector<string> result;
        for (int i = 0; i < dictionary.size(); ++i) {
            if (dictionary[i].length() > max_len) {
                result.clear();
                result.push_back(dictionary[i]);
                max_len = dictionary[i].length();
            } else if (dictionary[i].length() == max_len) {
                result.push_back(dictionary[i]);
            }
        }
        return result;
    }
};
