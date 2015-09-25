#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using std::stringstream;
using std::string;


class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
		char buf[100] = {0};
		sprintf(buf, "%d", n);
		bool neg = false;
		if (n < 0)
			neg = true;
		string str = neg ? buf + 1 : buf;
		std::reverse(str.begin(), str.end());
		sprintf(buf, "%s", str.c_str());
		
		int ntemp;
		sscanf(buf, "%d", &ntemp);
		
		std::cout << ntemp <<std::endl;
	//	std::cout << buf <<std::endl;
		//ss.str("");
		sprintf(buf, "%d", ntemp);
		std::cout <<"ss:" <<str.c_str() <<std::endl;
		int i = 0;
		while (str[i] == '0') i++;
		if (str.substr(i) == buf)
			return neg ? -ntemp : ntemp;
		else 
			return 0;
    }
};


int main() {
	/*
	stringstream ss;
	ss << 123;
	ss.str("");
	ss << 456;
	int n = 23423;
	ss << n;
	std::cout << "n:" << n <<"\trdstate:" << ss.fail() << std::endl;
	ss >> n;
	ss.str("");
	std::cout << "n:" << n <<"\trdstate:" << ss.fail() << std::endl;
	ss << n;
	std::cout << "n:" << n <<"\trdstate:" << ss.fail() << std::endl;
	ss << "2323";
	std::cout << "n:" << n <<"\trdstate:" << ss.fail() << "\tss:" << ss.str() << std::endl;
	std::cout << ss<< std::endl;
	*/
	Solution s;
	std::cout << s.reverseInteger(-10) << std::endl;
}