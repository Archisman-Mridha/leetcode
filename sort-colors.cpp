#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        void sortColors(vector<int>& nums) {

            int initialStartingPosition= 0;

            for(int i= 0; i < 2; i++) {
                queue<int> positions;

                for(int j= initialStartingPosition; j< nums.size( ); j++) {

                    if(nums[j] == i) {

                        if(!positions.empty( )) {
                            int targetPosition= positions.front( );
                            positions.pop( );

                            swap(nums[targetPosition], nums[j]);

                            positions.push(j);
                        }

                        initialStartingPosition++;
                    }

                    else positions.push(j);
                }
            }
        }
};