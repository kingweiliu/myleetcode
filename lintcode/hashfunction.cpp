class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long long threethree = 33;
        long long ex = 1;
        long long sum = 0;
        for (int i= key.length() - 1; i>= 0; --i) {
            sum += key[i] * ex ;
            sum %= HASH_SIZE;
            ex *= 33;
            ex %= HASH_SIZE;
        }
        return sum % HASH_SIZE;
    }
};
