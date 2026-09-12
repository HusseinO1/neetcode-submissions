class Solution {
public:
    int longestPath = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return longestPath; 
    }

private:
    int getDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftSize = getDepth(root->left);
        int rightSize = getDepth(root->right);

        longestPath = max(leftSize + rightSize, longestPath);
        
        return 1 + max(leftSize, rightSize);
    }
};