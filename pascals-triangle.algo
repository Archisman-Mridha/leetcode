#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> rows= { };

            //* manually adding the first row
            rows.push_back({1});

            if(numRows == 1)
                return rows;

            //* manually adding the second row
            rows.push_back({1, 1});

            if(numRows == 2)
                return rows;

            cout<<"debug";

            for(int row= 2; row < numRows; row++) {
                vector<int> rowElements= { };

                rowElements.push_back(1);

                for(int column= 1; column < row; column++)
                    rowElements.push_back(rows[row - 1][column -1] + rows[row - 1][column]);

                rowElements.push_back(1);

                rows.push_back(rowElements);
            }

            return rows;
        }
};