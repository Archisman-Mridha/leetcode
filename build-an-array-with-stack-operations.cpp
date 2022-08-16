#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<string> buildArray(vector<int>& target, int n) {
            vector<string> result= { };

            int targetIndexTracker= 0;

            for(int i= 1; i <= n; i++) {

                if(target[targetIndexTracker] == i) {
                    result.push_back("Push");

                    targetIndexTracker++;
                }

                else {
                    result.push_back("Push");
                    result.push_back("Pop");
                }

                if(targetIndexTracker >= target.size( ))
                    break;
            }

            return result;
        }
};