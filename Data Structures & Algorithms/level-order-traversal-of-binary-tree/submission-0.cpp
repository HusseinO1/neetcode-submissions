class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        // Base case: empty tree
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // Capture the number of nodes at the current level
            int levelSize = q.size();
            vector<int> currentLevel;

            // Process all nodes at this specific level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); // Use front() for queues
                q.pop();

                // Store the integer value, not the pointer
                currentLevel.push_back(node->val);

                // Push children to the queue for the NEXT level
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Add the current level to the final answer
            ans.push_back(currentLevel);
        }
        
        return ans;
    }
};