#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int slowPointer= 0;

            for(int fastPointer= 0; fastPointer< nums.size( ); fastPointer++) {
                if(nums[slowPointer] != 0)
                    slowPointer++;

                else if(nums[fastPointer] != 0)
                    if(fastPointer != slowPointer) {
                        swap(nums[slowPointer], nums[fastPointer]);

                        slowPointer++;
                    }
            }
        }
};