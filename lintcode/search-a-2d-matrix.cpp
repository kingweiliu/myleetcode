class Solution {
    
    int findbin(vector<int>& v, int r, int l, int target) {
        //std::cout << "r:" <<r <<", l:"<<l<<std::endl;
		if (l - r < 2)
			if (v[l] > target)
				return r;
			else	
				return l;
		
		int mid = (r+l)/2;
/*        std::cout << "r:" <<r <<", l:"<<l<<", mid:"<<mid <<", v[mid]:"<<v[mid]<<std::endl;
		for (int i= r; i<=l ; ++i) {
			std::cout << "vec:" << v[i] << std::endl;
		}
*/
        if (v[mid] < target)
			return findbin(v, mid, l, target);
        else
			return findbin(v, r, mid, target);
            
    }
    
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0)
            return false;
        vector<int> head;
        for (int i=0; i< matrix.size(); ++i) {
            head.push_back(matrix[i][0]);
        }
        
        int rowindex = findbin(head, 0, (int)(head.size() -1), target);
        if (rowindex < 0)
            return false;
        
		int colindex = findbin(matrix[rowindex], 0, (int)(matrix[rowindex].size() -1) , target);

		if (matrix[rowindex][colindex] == target)
            return true;
        return false;
    }
};