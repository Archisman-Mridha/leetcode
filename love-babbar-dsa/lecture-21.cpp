#include <bits/stdc++.h>

using namespace std;

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

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    vector<int> result= { };

    int i, j, carry= 0;

    for(i= n - 1, j= m - 1; i >= 0 && j >= 0; i--, j--) {
        int sumOfDigits= a.at(i) + b.at(j) + carry;

        carry= sumOfDigits / 10;
        sumOfDigits= sumOfDigits % 10;

        result.push_back(sumOfDigits);
    }

    while(i >= 0) {
        int sum= a[i] + carry;

        carry= sum / 10;
        sum= sum % 10;

        result.push_back(sum);

        i--;
    }

    while(j >= 0) {
        int sum= b[j] + carry;

        carry= sum / 10;
        sum= sum % 10;

        result.push_back(sum);

        j--;
    }

    if(carry > 0)
        result.push_back(carry);

    //* reverse result
    for(int i= 0; i < result.size( ) / 2; i++)
        swap(result[i], result[result.size( ) - 1 - i]);

    return result;
}