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
        queue<TreeNode*> storage;

    public:
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> result= { };

            if(root == NULL)
                return result;

            storage.push(root);

            while(!storage.empty( )) {
                storage.push(NULL);

                vector<int> currentLevelValues= { };

                while(storage.front( ) != NULL) {
                    TreeNode *poppedNode= storage.front( );
                    storage.pop( );

                    currentLevelValues.push_back(poppedNode->val);

                    if(poppedNode->left != NULL)
                        storage.push(poppedNode->left);

                    if(poppedNode->right != NULL)
                        storage.push(poppedNode->right);
                }

                result.push_back(currentLevelValues);

                storage.pop( );
            }

            return result;
        }
};