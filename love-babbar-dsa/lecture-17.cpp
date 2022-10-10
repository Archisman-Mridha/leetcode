#include <bits/stdc++.h>

using namespace std;

//* Bubble sort

//* space complexity= O(1) and time complexity= O(n^2)

void bubbleSort(vector<int>& array, int n) {

    for(int i= n - 1; i > 0; i++)
        for(int j= 0; j< i; j++)
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);
}