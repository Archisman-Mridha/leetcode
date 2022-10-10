#include <bits/stdc++.h>

using namespace std;

/*
    * Selection sort

    similar to a boxing round, here we have multiple rounds. In each round we pick the smallest element move it to it's right place.
*/

//! space complexity= O(1) and time complexity= O(n^2)

void selectionSort(vector<int>& array, int n) {

    for(int i= 0; i< n - 1; i++) {
        int smallestElementPosition= i;

        for(int j= i + 1; j< n; j++)
            if(array[j] < array[smallestElementPosition])
                smallestElementPosition= j;

        if(smallestElementPosition != i)
            swap(array[i], array[smallestElementPosition]);
    }
}