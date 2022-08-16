#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        int findCenter(vector<vector<int>>& edges) {

            vector<int> firstEdge= edges[0],
                secondEdge= edges[1];

            for(int i= 0; i< firstEdge.size( ); i++)
                for(int j= 0; j< secondEdge.size( ); j++)
                    if(firstEdge[i] == secondEdge[j])
                        return firstEdge[i];

            return 0;
        }
};