#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        int reverseNumber(int x) {
            long int reverse= 0;

            while(x != 0) {
                int digitFromLast= x % 10;

                reverse= (reverse * 10) + digitFromLast;

                x= x / 10;
            }

            return reverse;
        }

    public:
        bool isPalindrome(int x) {

            if(x < 0)
                return false;

            else if(x < 10)
                return true;

            //* get the reverse of the number
            long int reverse= reverseNumber(x);

            return reverse == x;
        }
};