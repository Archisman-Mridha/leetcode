#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int currentNums1LastElementPosition= m - 1;

            //* starting from the last element of nums2
            for(int i= n - 1; i >= 0; i--) {

                //* place the element at last position of nums1
                nums1[currentNums1LastElementPosition + 1]= nums2[i];
                currentNums1LastElementPosition += 1;

                //* change its position to the right place in nums1

                int currentPosition= currentNums1LastElementPosition;

                while(currentPosition > 0 && nums1[currentPosition] < nums1[currentPosition - 1]) {
                    swap(nums1[currentPosition], nums1[currentPosition - 1]);

                    currentPosition -= 1;
                }
            }
        }
};