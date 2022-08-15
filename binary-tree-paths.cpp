#include <bits/stdc++.h>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left, *right;

    TreeNode(int x= 0)
        : val(x), left(NULL), right(NULL)
    { }
};

class Solution {

    public:
        vector<string> binaryTreePaths(TreeNode *root) {
            if(root == NULL)
                return { };

            vector<string> leftSubtreePaths= binaryTreePaths(root->left),
                rightSubtreePaths= binaryTreePaths(root->right);

            if(leftSubtreePaths.size( ) == 0 && rightSubtreePaths.size( ) == 0)
                leftSubtreePaths.push_back(to_string(root->val));

            else {
                for(int i= 0; i< leftSubtreePaths.size( ); i++)
                    leftSubtreePaths[i]= to_string(root->val) + "->" + leftSubtreePaths[i];

                for(int i= 0; i< rightSubtreePaths.size( ); i++)
                    rightSubtreePaths[i]= to_string(root->val) + "->" + rightSubtreePaths[i];

                leftSubtreePaths.insert(leftSubtreePaths.end( ), rightSubtreePaths.begin( ), rightSubtreePaths.end( ));
            }

            return leftSubtreePaths;
        }
};