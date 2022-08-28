#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        void exploreAdjacentNodes(int m, int n, vector<vector<int>>& isVerticesVisited, vector<vector<char>>& grid) {
            queue<pair<int, int>> storage= { };

            storage.push(make_pair(m, n));
            isVerticesVisited[m][n]= 1;

            while(!storage.empty( )) {
                pair<int, int> vertex= storage.front( );

                int row= vertex.first, column= vertex.second;

                for(int i= -1; i <= 1; i++)
                    for(int j= -1; j <= 1; j++) {

                        if(abs(i) == abs(j) || (i == 0 && j == 0))
                            continue;

                        int neighbourRow= row + i, neighbourColumn= column + j;

                        if(neighbourRow >= 0 && neighbourRow < grid.size( ) && neighbourColumn >= 0 && neighbourColumn < grid[0].size( ))
                            if(grid[neighbourRow][neighbourColumn] == '1' && isVerticesVisited[neighbourRow][neighbourColumn] == 0) {
                                storage.push(make_pair(neighbourRow, neighbourColumn));

                                isVerticesVisited[neighbourRow][neighbourColumn]= 1;
                            }
                    }

                storage.pop( );
            }
        }

    public:
        int numIslands(vector<vector<char>>& grid) {
            int count= 0;

            const int numRows= grid.size( ),
                numColumns= grid[0].size( );

            vector<vector<int>> isVerticesVisited(numRows, vector<int>(numColumns, 0));

            for(int m= 0; m < numRows; m++)
                for(int n= 0; n < numColumns; n++)
                    if(grid[m][n] == '1' && isVerticesVisited[m][n] == 0) {
                        ++count;

                        exploreAdjacentNodes(m, n, isVerticesVisited, grid);
                    }

            return count;
        }
};