class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Swap the left and right pointers
        std::swap(root->left, root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};