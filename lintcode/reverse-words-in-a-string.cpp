class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
		std::map<char, int> ma, mb;
		for (int i=0;i<A.length();++i)
			if (ma.count(A[i]))
				ma[A[i]] ++;
			else 
				ma[A[i]] = 1;
		
		for (int i=0;i<B.length();++i)
			if (mb.count(B[i]))
				mb[B[i]] ++;
			else 
				mb[B[i]] = 1;
			
		std::map<char, int>::iterA = ma.begin();
		for(; iterA!= ma.end(); ++iter) {
			if (!mb.count(iterA->first) || ma[iterA->first] < mb[iterA->first]]) {
				return false;
			}
		}
		return true;
    }
};
