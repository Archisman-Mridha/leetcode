#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        int climbStairs(int n) {

            if(n <= 2)
                return n;

            int secondOffset= 1, prev= 2, result= 0;

            for(int i= 3; i <= n; i++) {
                result= secondOffset + prev;

                secondOffset= prev;
                prev= result;
            }

            return result;
        }
};