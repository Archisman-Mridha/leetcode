#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        void recursiveHelper(int currentVertex, vector<int> *adj, bool *isVertexVisited, vector<int>& result) {

            if(isVertexVisited[currentVertex])
                return;

            isVertexVisited[currentVertex]= true;
            result.push_back(currentVertex);

            for(int i= 0; i< adj[currentVertex].size( ); i++)
                recursiveHelper(adj[currentVertex][i], adj, isVertexVisited, result);
        }

    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[ ]) {
            vector<int> result= { };

            bool isVertexVisited[V]= { false };

            recursiveHelper(0, adj, isVertexVisited, result);

            return result;
        }
};