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
private:
    int DFS(TreeNode* root, int& diameter)
    {
        if(root == nullptr) return 0;

        int leftMaxDepth = DFS(root->left, diameter);
        int rightMaxDepth = DFS(root->right, diameter);
        diameter = max(diameter, leftMaxDepth + rightMaxDepth);
        return 1 + max(leftMaxDepth, rightMaxDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;
        DFS(root, diameter);
        return diameter;
    }
};
