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
    int maxLevelSum(TreeNode* root) {
       
        if(root==NULL) return 0;
        int maxi = INT_MIN;
        int ans_level = 1;
        int currLevel = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
    
            int sz = q.size();
            int total = 0;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                 q.pop();
                total += node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            
           if(total>maxi)
           {
              maxi = total;
              ans_level = currLevel;
           }

           currLevel++;

        }

        return ans_level;

    }
};
