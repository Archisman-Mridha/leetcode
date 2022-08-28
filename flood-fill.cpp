#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            queue<pair<int, int>> storage= { };

            vector<vector<int>> isVerticesVisited(image.size( ), vector<int>(image[0].size( ), 0));

            int pixelValue= image[sr][sc];

            storage.push(make_pair(sr, sc));
            isVerticesVisited[sr][sc]= 1;

            do {
                pair<int, int> grid= storage.front( );

                image[grid.first][grid.second]= color;

                for(int i= -1; i <= 1; i++)
                    for(int j= -1; j <= 1; j++) {

                        if((abs(i) == abs(j)) || (i == 0 && j == 0))
                            continue;

                        int neighbourRow= grid.first + i, neighbourColumn= grid.second + j;

                        if(neighbourRow >= 0 && neighbourColumn >= 0 && neighbourRow < image.size( ) && neighbourColumn < image[0].size( ))
                            if(image[neighbourRow][neighbourColumn] == pixelValue && isVerticesVisited[neighbourRow][neighbourColumn] == 0) {
                                storage.push(make_pair(neighbourRow, neighbourColumn));

                                isVerticesVisited[neighbourRow][neighbourColumn]= 1;
                            }
                    }

                storage.pop( );
            } while(!storage.empty( ));

            return image;
        }
};