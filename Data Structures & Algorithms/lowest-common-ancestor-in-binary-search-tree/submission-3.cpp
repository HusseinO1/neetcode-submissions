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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val;
        int pVal = p->val;

        int qVal = q->val;

        if(pVal == qVal && qVal == rootVal) return root;

        if(pVal <= rootVal && qVal >= rootVal || pVal >= rootVal && qVal <= rootVal) return root; 

        if(qVal < rootVal && pVal < rootVal) return lowestCommonAncestor(root->left, p, q);
        
        if(qVal > rootVal || pVal > rootVal) return lowestCommonAncestor(root->right, p, q);
    }
};
