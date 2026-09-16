/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return bDFS(root) != -1;
    }

    int bDFS(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int lD = bDFS(root->left);
        int rD = bDFS(root->right);

        if(lD == -1 || rD == -1) return -1;

        if(abs(lD - rD) > 1) return -1;

        return 1 + max(lD, rD);
    }
};
