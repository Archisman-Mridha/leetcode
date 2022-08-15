#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        map<int, int> storage;

    public:
        int fib(int n) {

            if(n < 2)
                return n;

            auto iterator= storage.find(n);

            if(iterator != storage.end( ))
                return iterator->second;

            else {
                int result= fib(n - 1) + fib(n - 2);

                storage.insert({ n, result });

                return result;
            }
        }
};