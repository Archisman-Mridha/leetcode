#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        bool recursiveHelper(int n) {

            if(n == 1)
                return true;

            else if(n % 2 != 0)
                return false;

            else return recursiveHelper(n / 2);
        }

    public:
        bool isPowerOfTwo(int n) {

            if(n <= 0)
                return false;

            else return recursiveHelper(n);
        }
};