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
    bool isBalanced(TreeNode* root)
    {
        if(!root) return true;

        if(maxDepth(root) == -1) return false;

        return true;
    }
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int leftMaxDepth = maxDepth(root->left);
        if(leftMaxDepth == -1) return -1;
        int rightMaxDepth = maxDepth(root->right);
        if(rightMaxDepth == -1 || abs(rightMaxDepth - leftMaxDepth) > 1) return -1;
        return 1 + max(leftMaxDepth, rightMaxDepth);
    }
};
