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
    int maxPathSum(TreeNode* root)
    {
        int maxVal = root->val;
        dDFS(root, maxVal);
        return maxVal;
    }

    int dDFS(TreeNode* root, int& maxVal)
    {
        if(root == nullptr) return 0;

        int lS = dDFS(root-> left, maxVal);

        int rS = dDFS(root->right, maxVal);

        maxVal = max(maxVal, max(0, lS) + max(0, rS) + root->val);

        return max(0, max(lS, rS)) + root->val;
    }
};
