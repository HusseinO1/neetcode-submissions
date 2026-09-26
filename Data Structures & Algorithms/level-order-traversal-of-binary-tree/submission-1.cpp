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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);

        while(!q.empty())
        {
            vector<int> currLevel;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                currLevel.push_back(currNode->val);

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};
