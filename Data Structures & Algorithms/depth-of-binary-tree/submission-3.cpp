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
    int maxDepth(TreeNode* root) {
        return DFS(root, 1);
    }

    int DFS(TreeNode* node, int depth)
    {
        if(node == nullptr) return depth - 1;

        int leftMaxDepth = DFS(node->left, depth + 1);
        int rightMaxDepth = DFS(node->right, depth + 1);

        return max(leftMaxDepth, rightMaxDepth);
    }
};
