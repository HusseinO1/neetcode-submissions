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
    int numGood = 0;
    int goodNodes(TreeNode* root) {
        dFS(root, root->val);
        return numGood;
    }
    void dFS(TreeNode* node, int maxNum)
    {
        if(node == nullptr) return;

        if(node->val >= maxNum)
        {
            numGood++;
            maxNum = node->val;
        }

        dFS(node->left, maxNum);

        dFS(node->right, maxNum);
    }
};
