#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        void rotate(vector<vector<int>>& matrix) {

            //* transpose the matrix
            for(int i= 0; i< matrix.size( ); i++)
                for(int j= 0; j <= i; j++)
                    swap(matrix[i][j], matrix[j][i]);

            //* reverse each row of the transposed matrix

            int columnCount= matrix[0].size( );

            for(int i= 0; i< matrix.size( ); i++)
                for(int j= 0; j< columnCount / 2; j++)
                    swap(matrix[i][j], matrix[i][columnCount - j - 1]);
        }
};