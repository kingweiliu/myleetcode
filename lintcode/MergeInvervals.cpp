#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;


struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
 };

 /**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

// 空输入 
// std::sort的使用
// vector的项的删除

class Solution {
private:
    static bool cmp_interval(Interval v1, Interval v2) {
         return v1.start < v2.start;
    }
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.size() == 0) 
            return intervals;
        std::sort(intervals.begin(), intervals.end(), cmp_interval);
        vector<Interval>::iterator iter , iternext ;
        iter = intervals.begin();
        iternext = iter + 1;
        while (iternext != intervals.end()) {
            if (iternext->start <= iter->end) {
                if (iternext->end > iter->end) 
                    iter->end = iternext->end;{
                }
                // 删除iternext
                iternext = intervals.erase(iternext);
            } else {
                iter = iternext;
                iternext ++;
            }
        }
        return intervals;
    }
};

int main() {
    Solution s;
    vector<Interval> v;
    s.merge(v);
}

