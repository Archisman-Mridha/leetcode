#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        void reverseString(vector<char> &s) {

            if(s.size( ) == 1)
                return;

            char temporary;

            for(int i= s.size( ) - 1; i >= floor(s.size( ) / 2); i--) {
                temporary= s[s.size( ) - 1 - i];

                s[s.size( ) - 1 - i]= s[i];
                s[i]= temporary;
            }
        }
};