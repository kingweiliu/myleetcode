#include <vector>
#include <iostream>

using std::vector;

// 要细心，争取一次ac。
class Solution {
private:
    void markIsland(vector<vector<bool> >& grid, vector<vector<bool> >& flag, int row, int col, int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col)
            return;

        if (flag[r][c]) 
            return;
        if (!grid[r][c])
            return;
        if (grid[r][c])
            flag[r][c] = true;
        std::cout<<"r:"<<r<<", c:"<<c<<std::endl;
        markIsland(grid, flag, row, col, r-1, c);  
        markIsland(grid, flag, row, col, r+1, c);  
        markIsland(grid, flag, row, col, r, c+1);  
        markIsland(grid, flag, row, col, r, c-1);  
        
    }
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here
        int count = 0;
        vector<vector<bool> > flag;
        for (int i =0; i< grid.size(); ++i) {
            flag.push_back(vector<bool>(grid[i].size(), false));
        }

        std::cout<<1<<std::endl;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j=0; j < grid[i].size(); ++j) {
                std::cout<<"x:"<<i<<", y:"<<j<<std::endl;
                if (grid[i][j] && !flag[i][j]) {
                    markIsland(grid, flag, grid.size(), grid[i].size(), i, j);
                    count ++;
                }
            }
        }
        std::cout<<count<<std::endl;
        return count;
    }
};


int main() {
    bool v[5][5] = {{1,1,0,0,0},{0,1,0,0,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,1}};
    vector<vector<bool> > vv;
    for(int i = 0; i< 5; i++) {
        vv.push_back(vector<bool>(v[i], v[i] +5));
    }
    vector<bool> a= vector<bool>(3, false);
//    std::cout << a.size() <<std::endl;


    Solution s;
    std::cout << s.numIslands(vv) << std::endl;
}
