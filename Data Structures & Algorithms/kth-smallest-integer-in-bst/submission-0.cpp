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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }

private:
    void inorder(TreeNode* node, int k, int& count, int& result) {
        // Base case: if node is null, or we've already found the kth element, stop.
        if (!node || count >= k) {
            return;
        }
        
        // 1. Go to the "final left most node"
        inorder(node->left, k, count, result);
        
        // 2. "Start counting" (process current node)
        count++;
        if (count == k) {
            result = node->val;
            return; 
        }
        
        // 3. "Go to the right ward ones too"
        inorder(node->right, k, count, result);
    }
};