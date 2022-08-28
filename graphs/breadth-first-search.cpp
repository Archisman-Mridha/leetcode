#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<int> bfsOfGraph(int V, vector<int> adj[ ]) {
            vector<int> result= { };

            bool isVertexVisited[V]= { false };

            queue<int> storage;

            storage.push(0);
            isVertexVisited[0]= true;

            do {
                int vertex= storage.front( );

                for(int i= 0; i< adj[vertex].size( ); i++) {
                    int connectedVertex= adj[vertex][i];

                    if(!isVertexVisited[connectedVertex]) {
                        storage.push(connectedVertex);

                        isVertexVisited[connectedVertex]= true;
                    }
                }

                storage.pop( );
                result.push_back(vertex);
            } while(!storage.empty( ));

            return result;
        }
};