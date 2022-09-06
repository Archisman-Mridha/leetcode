#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:

        void setRowZero(int row, vector<int>& rowMemo, vector<vector<int>>& matrix) {

            for(int i= 0; i< matrix[0].size( ); i++)
                matrix[row][i]= 0;

            rowMemo[row]= 1;
        }

        void setColumnZero(int column, vector<int>& columnMemo, vector<vector<int>>& matrix) {

            for(int i= 0; i< matrix.size( ); i++)
                matrix[i][column]= 0;

            columnMemo[column]= 1;
        }

    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int rowCount= matrix.size( ), columnCount= matrix[0].size( );

            vector<pair<int, int>> targetPositions= { };

            for(int row= 0; row< rowCount; row++)
                for(int column= 0; column< columnCount; column++)
                    if(matrix[row][column] == 0)
                        targetPositions.push_back({ row, column });

            vector<int> rowMemo(rowCount, 0), columnMemo(columnCount, 0);

            for(int i= 0; i< targetPositions.size( ); i++) {

                int row= targetPositions[i].first, column= targetPositions[i].second;

                if(rowMemo[row] == 0)
                    setRowZero(row, rowMemo, matrix);

                if(columnMemo[column] == 0)
                    setColumnZero(column, columnMemo, matrix);
            }
        }
};