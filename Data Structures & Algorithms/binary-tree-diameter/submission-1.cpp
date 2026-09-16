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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxSize = 0;

        dDFS(root, maxSize);

        return maxSize;
    }
private:
    int dDFS(TreeNode* root, int& maxSize)
    {
        if(root == nullptr) return 0;

        int lD = dDFS(root->left, maxSize);
        int rD = dDFS(root->right, maxSize);

        maxSize = max(maxSize, lD + rD);

        return 1 + max(lD, rD);
    }
};
