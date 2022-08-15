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

    private:
        vector<int> recursiveHelper(TreeNode *root) {

            if(root == NULL)
                return { };

            vector<int> leftSubtreeResult= recursiveHelper(root->left);
            vector<int> rightSubtreeResult= recursiveHelper(root->right);

            if(leftSubtreeResult.size( ) == 0 && rightSubtreeResult.size( ) == 0)
                leftSubtreeResult.push_back(root->val);

            else {
                for(int i= 0; i< leftSubtreeResult.size( ); i++)
                    leftSubtreeResult[i]= root->val + leftSubtreeResult[i];

                for(int i= 0; i< rightSubtreeResult.size( ); i++)
                    rightSubtreeResult[i]= root->val + rightSubtreeResult[i];

                leftSubtreeResult.insert(leftSubtreeResult.end( ), rightSubtreeResult.begin( ), rightSubtreeResult.end( ));
            }

            return leftSubtreeResult;
        }

    public:
        bool hasPathSum(TreeNode *root, int targetSum) {
            vector<int> sums= recursiveHelper(root);

            for(int i= 0; i< sums.size( ); i++)
                if(sums[i] == targetSum)
                    return true;

            return false;
        }
};