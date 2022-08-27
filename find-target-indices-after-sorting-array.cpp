#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<int> targetIndices(vector<int>& nums, int target) {
            sort(nums.begin( ), nums.end( ));

            vector<int> indices= { };

            int firstOccurencePosition= 0;

            int lowerLimit= 0, upperLimit= nums.size( ) - 1, middlePosition;

            while(lowerLimit <= upperLimit) {
                middlePosition= lowerLimit + ((upperLimit - lowerLimit) / 2);

                if(nums[middlePosition] == target) {
                    firstOccurencePosition= middlePosition;

                    upperLimit= middlePosition - 1;
                }

                else if(nums[middlePosition] > target)
                    upperLimit= middlePosition - 1;

                else lowerLimit= middlePosition + 1;
            }

            int lastOccurencePosition= INT_MIN;

            lowerLimit= 0, upperLimit= nums.size( ) - 1;

            while(lowerLimit <= upperLimit) {
                middlePosition= lowerLimit + ((upperLimit - lowerLimit) / 2);

                if(nums[middlePosition] == target) {
                    lastOccurencePosition= middlePosition;

                    lowerLimit= middlePosition + 1;
                }

                else if(nums[middlePosition] > target)
                    upperLimit= middlePosition - 1;

                else lowerLimit= middlePosition + 1;
            }

            if(firstOccurencePosition == lastOccurencePosition)
                indices.push_back(firstOccurencePosition);

            else if(firstOccurencePosition < lastOccurencePosition)
                for(int i= firstOccurencePosition; i<= lastOccurencePosition; i++)
                    indices.push_back(i);

            return indices;
        }
};