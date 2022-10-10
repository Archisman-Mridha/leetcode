#include <bits/stdc++.h>

using namespace std;

//* Insertion sort

void insertionSort(int n, vector<int>& array) {

    for(int i= 1; i< n; i++) {

        int targetPosition= i;

        while(array[i] < array[targetPosition - 1])
            targetPosition--;

        if(targetPosition != i)
            for(int j= i; j > targetPosition; j--)
                swap(array[j], array[j - 1]);
    }
}