#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int minuteCount= 0;

            //* find position of initial rotten oranges

            queue<pair<int, int>> rottenOrangesPositions;

            for(int i= 0; i< grid.size( ); i++)
                for(int j= 0; j< grid[0].size( ); j++)
                    if(grid[i][j] == 2)
                        rottenOrangesPositions.push({i, j});

            if(!rottenOrangesPositions.empty( ))
                rottenOrangesPositions.push({-1, -1});

            while(! rottenOrangesPositions.empty( )) {

                //* in a single minute, perform action for each rotten orange

                while(rottenOrangesPositions.front( ) != make_pair(-1, -1)) {

                    int row= rottenOrangesPositions.front( ).first,
                        column= rottenOrangesPositions.front( ).second;

                    for(int di= -1; di <= 1; di++)
                        if(row + di >= 0 && row + di < grid.size( ))
                            for(int dj= -1; dj <= 1; dj++)
                                if(column + dj >= 0 && column + dj < grid[0].size( )) {

                                    int adjacentRow= row + di, adjacentColumn= column + dj;

                                    if(abs(di) == abs(dj))
                                        continue;

                                    else if(grid[adjacentRow][adjacentColumn] == 1) {
                                        grid[adjacentRow][adjacentColumn] = 2;

                                        rottenOrangesPositions.push({adjacentRow, adjacentColumn});
                                    }
                                }

                    rottenOrangesPositions.pop( );
                }

                rottenOrangesPositions.pop( );

                if(!rottenOrangesPositions.empty( )) {
                    minuteCount++;

                    rottenOrangesPositions.push({-1, -1});
                }
            }

            for(int i= 0; i< grid.size( ); i++)
                for(int j= 0; j< grid[0].size( ); j++)
                    if(grid[i][j] == 1)
                        return -1;

            return minuteCount;
        }
};
