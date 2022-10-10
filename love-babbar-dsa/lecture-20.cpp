#include <bits/stdc++.h>

using namespace std;

void reverseArray(vector<int>& array, int m) {

    for(int i= m + 1, j= array.size( ) - 1; i < j; i++, j--)
        swap(array[i], array[j]);
}

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