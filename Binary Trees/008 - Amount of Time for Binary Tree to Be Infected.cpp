https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    
    TreeNode* make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track, int start)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start) res = curr;

            if(curr->left)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return res;

    }

    int maxiDistance(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* target)
    {
        int maxi = 0;
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        while(!q.empty())
        {
            int sz = q.size();
            bool flag = false; // at end if any direction is burn then we can increase the maxi
            for(int i=0;i<sz;i++)
            {
               TreeNode* curr = q.front();
               q.pop();
               if(curr->left && !vis[curr->left]) {
                   flag = true;
                   vis[curr->left] = true;
                   q.push(curr->left);
               }

               if(curr->right && !vis[curr->right]) {
                flag = true;
                vis[curr->right] = true;
                q.push(curr->right);
               }

               if(parent_track[curr] && !vis[parent_track[curr]]) {
                   flag = true;
                   vis[parent_track[curr]] = true;
                   q.push(parent_track[curr]);
               }
            }

            if(flag) maxi++;
        }

        return maxi;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* target = make_parent(root,mp,start);
        int maxi = maxiDistance(root,mp,target);
        return maxi;
    }
};
