#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {

            int n= nums.size( );

            if(k >= n)
                k= k % n;

            //* reverse from 0 to n - k - 1

            for(int i= 0; i <= (n - 1 - k) / 2; i++)
                swap(nums[i], nums[n - 1 - k - i]);

            //* reverse from n - k to n - 1

            int j= 0;

            for(int i= n - k; i < (n - k + k/2); i++) {
                swap(nums[i], nums[n - 1 - j]);

                j++;
            }

            //* reverse whole array

            for(int i= 0; i< n / 2; i++)
                swap(nums[i], nums[n - i - 1]);
        }
};