https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        make_parent(root,parent_track);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int currlevel = 0;
        while(!q.empty())
        {
            int sz = q.size();
            if(currlevel == k) break;
            currlevel++;

            for(int i=0;i<sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if(curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]])
                {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }

        vector<int>res;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;
    }
};
