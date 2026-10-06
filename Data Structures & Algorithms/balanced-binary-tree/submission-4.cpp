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
        if(HeightDFS(root) == -1) return false;

        return true;
    }

    int HeightDFS(TreeNode* node)
    {
        if(node == nullptr) return 0;

        int leftHeight = HeightDFS(node->left);
        int rightHeight = HeightDFS(node->right);

        if(leftHeight == -1 || rightHeight == -1) return -1;
        
        int difference = abs(leftHeight - rightHeight);

        return difference <= 1 ? max(leftHeight, rightHeight) + 1 : -1;
    }
};
