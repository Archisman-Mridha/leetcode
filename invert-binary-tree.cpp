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
        TreeNode* temporaryStorageNode;

        void recursiveHelper(TreeNode *root) {

            if((root == NULL) || (root->left == NULL && root->right == NULL))
                return;

            temporaryStorageNode= root->left;
            root->left= root->right;
            root->right= temporaryStorageNode;

            temporaryStorageNode= NULL;

            recursiveHelper(root->left);
            recursiveHelper(root->right);

            return;
        }

    public:
        TreeNode* invertTree(TreeNode *root) {
            recursiveHelper(root);

            return root;
        }
};