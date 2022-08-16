#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        int searchInsert(vector<int>& nums, int target) {

            int lowerBound= 0,
                upperBound= nums.size( ) - 1,
                middleIndex;

            while(lowerBound < upperBound) {
                middleIndex= lowerBound + ceil((upperBound - lowerBound) / 2);

                if(nums[middleIndex] == target)
                    return middleIndex;

                else if(nums[middleIndex] > target)
                    upperBound= middleIndex - 1;

                else lowerBound= middleIndex + 1;
            }

            if(target < nums[lowerBound])
                return lowerBound;

            else if(target == nums[lowerBound])
                return lowerBound;

            else return lowerBound + 1;
        }
};