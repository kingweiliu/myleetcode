/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 

#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

// abs 函数在那个文件中
// set 的接口使用
// 深层嵌套循环时，结束的标记
// 空输入时的处理
// 全是同一个点的输入处理
// 算法复杂度 , 超时了
using std::set;
using std::vector;
using std::string;
using std::stringstream;

class Solution {
    public:
    std::string point_hash(const Point& p, int m) {
        std::stringstream ss;
        ss << p.x <<"," << p.y<<","<<m;
        return ss.str();
    }
    

public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here

        vector<string> points_hash;
        
        int m = 0;

        for (vector<Point>::iterator iter = points.begin(); iter != points.end(); ++iter, ++m) {
            points_hash.push_back(point_hash(*iter, m));
        }

        vector<set<string> > point_groups;

        
        for (int i = 0; i < points.size(); ++i) {
           const Point& pnt1 = points[i];
           string pnt1_hash = points_hash[i];
           std::cout << "ptn1:hash:" << pnt1_hash <<std::endl;
           for (int j = i + 1; j < points.size(); ++j) {
                const Point& pnt2 = points[j];
                string pnt2_hash = points_hash[j];

                std::cout << std::endl << "ptn2:hash:" << pnt2_hash <<std::endl;
                bool bFind = false;
                std::cout << "pg_size" << point_groups.size()<<std::endl;
                for (vector<set<string> >::iterator set_iter = point_groups.begin(); set_iter != point_groups.end();
                        ++set_iter) {
                 
                    std::cout << "check set :" << *(set_iter->begin()) <<std::endl;
                    if (set_iter->count(pnt1_hash) && set_iter->count(pnt2_hash)) {
                        bFind = true;
                        break;
                    }
                }
                std::cout << "check set end result:" << bFind <<std::endl;
                if (bFind) 
                    continue;
                set<string> group;
                group.insert(pnt1_hash);
                group.insert(pnt2_hash);

                if (pnt1.x == pnt2.x) {
                    for (int k = j + 1; k < points.size(); ++k ) {
                        std::cout << "ptn3:hash:" << points_hash[k]<<std::endl;
                        if (points[k].x == pnt1.x) {
                            group.insert(points_hash[k]); 
                        }
                    }
                } else if (pnt1.y == pnt2.y) {
                    for (int k = j + 1; k < points.size(); ++k ) {
                        if (points[k].y == pnt1.y) {
                            group.insert(points_hash[k]); 
                        }
                    }
                } else {
                    double a = (double)(pnt1.y - pnt2.y) / (pnt1.x - pnt2.x);
                    double b = pnt1.y - a * pnt1.x;
                    for (int k = j + 1; k < points.size(); ++k ) {
                    std::cout<<"a, b:" << a << ", " << b << ",k:" << k << std::endl;
                        if (std::abs(points[k].x * a + b - points[k].y) < 1e-7) {
                            group.insert(points_hash[k]); 
                        }
                    }
                   
                }
                std::cout << "group_size:" << group.size()<<std::endl;
                if (group.size() > 2) {
                    point_groups.push_back(group);
                }
                
                    
           }
           std::cout << "pnt1 end" << points_hash[i] <<std::endl; 
        } 

        int max_count = 2;

        for (vector<set<string> >::iterator iter = point_groups.begin(); iter != point_groups.end(); ++iter) {
            if (iter->size() > max_count) {
                max_count = iter->size();
            }
        }
        
        return std::min((int)points.size(), max_count);

    }
};


int main() {
    // [[1,2],[3,6],[0,0],[1,3]]
    vector<Point> v;
    /*
    v.push_back(Point(1, 2));
    v.push_back(Point(3, 6));
    v.push_back(Point(0, 0));
    v.push_back(Point(1, 3));
    */

    v.push_back(Point(1, 1));
    v.push_back(Point(1, 1));
    v.push_back(Point(1, 1));
    Solution s;
    std::cout << s.point_hash(v[1], 0) << std::endl; 
    std::cout << s.maxPoints(v);}

