#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        void recursiveHelper(int currentVertex, vector<int> *adj, bool *isVertexVisited) {

            if(isVertexVisited[currentVertex])
                return;

            isVertexVisited[currentVertex]= true;

            for(int i= 0; i< adj[currentVertex].size( ); i++)
                recursiveHelper(adj[currentVertex][i], adj, isVertexVisited);
        }

    public:
        int findCircleNum(vector<vector<int>>& adj) {

            const int V= adj.size( );

            // convert adjacency matrix to adjacency list

            vector<int> adjList[adj.size( )];

            for(int m= 0; m< adj.size( ); m++)
                for(int n= 0; n < adj[m].size( ); n++)
                    if(adj[m][n] == 1 && m != n) {

                        adjList[m].push_back(n);
                        adjList[n].push_back(m);
                    }

            int provinceCount= 0;

            bool isVertexVisited[adj.size( )];

            for(int i= 0; i< adj.size( ); i++)
                isVertexVisited[i]= false;

            for(int i= 0; i < V; i++)
                if(isVertexVisited[i] == false) {
                    ++provinceCount;

                    recursiveHelper(i, adjList, isVertexVisited);
                }

            return provinceCount;
        }
};