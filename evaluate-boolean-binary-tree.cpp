#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr)
    { }
};

class Solution {

    public:
        bool evaluateTree(TreeNode* root) {
            if(root == NULL)
                return true;

            else if(root->val < 2)
                return root->val;

            bool leftSubtreeValue= evaluateTree(root->left),
                rightSubtreeValue= evaluateTree(root->right);

            if(root->val == 2)
                return leftSubtreeValue || rightSubtreeValue;

            else return leftSubtreeValue && rightSubtreeValue;
        }
};