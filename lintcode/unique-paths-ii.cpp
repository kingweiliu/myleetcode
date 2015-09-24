#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
		if (row == 0 || obstacleGrid[0].size() == 0)
            return 0;
        // write your code here
        int board[100][100] = {0};
        
		
		int col = obstacleGrid[0].size();
		
        board[0][0] = obstacleGrid[0][0] ? 0 : 1;
		std::cout << board[0][0] << "\t";
        for (int j= 1; j<col; ++j) {
            board[0][j] = obstacleGrid[0][j] ? 0 : board[0][j - 1];
			std::cout << board[0][j] << "\t";
        }
		
			std::cout << std::endl;
        
        for (int i= 1; i< row; ++i) {
             board[i][0] = obstacleGrid[i][0] ? 0 : board[i-1][0];
            for (int j=1; j< col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    board[i][j] = 0;
                } else 
                    board[i][j] = board[i-1][j] + board[i][j-1];
            }
			
			for (int j =0; j< col; ++j)
				std::cout << board[i][j] << "\t";
			std::cout << std::endl;
			
			
        }
        return board[row-1][col-1];
    }
};


int main() {
	Solution s;
	vector<vector<int> > obstacleGrid;
	int a[12][7] = {
{0,0,0,1,0,0,0},
{1,0,0,0,0,0,0},
{0,1,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,1,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,1,0,0,0,0,0},
{0,0,0,0,0,0,1},
{0,1,0,0,0,0,0}
        	};

	for (int i = 0;i< 12; ++i) {
		vector<int> abc(a[i], a[i] + 6);	
		obstacleGrid.push_back(abc);
	}
	std::cout <<s.uniquePathsWithObstacles(obstacleGrid);

}
