#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            bool rotationDetected= false;

            for(int i= 0; i< nums.size( ) - 1; i++)
                if(nums[i] > nums[i + 1]) {
                    if(!rotationDetected)
                        rotationDetected= true;

                    else return false;
                }

            if(rotationDetected)
                return nums[nums.size( ) - 1] <= nums[0];

            else return true;
        }
};