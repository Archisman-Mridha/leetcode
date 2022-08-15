#include <bits/stdc++.h>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left, *right;

    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    { }
};

class Solution {

    private:
        pair<int, bool> recursiveHelper(TreeNode *root) {

            if(root == NULL)
                return make_pair(0, true);

            pair<int, bool> leftSubtreeResult= recursiveHelper(root->left),
                rightSubtreeResult= recursiveHelper(root->right);

            if(!leftSubtreeResult.second || !rightSubtreeResult.second)
                return make_pair(0, false);

            int currentTreeHeight= max(leftSubtreeResult.first, rightSubtreeResult.first) + 1;
            bool isCurrentTreeHeightBalanced= abs(leftSubtreeResult.first - rightSubtreeResult.first) <= 1;

            return make_pair(currentTreeHeight, isCurrentTreeHeightBalanced);
        }

    public:
        bool isBalanced(TreeNode *root) {
            return recursiveHelper(root).second;
        }
};