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

        // 1-> Here 1st naive approach is do any dfs traversals store in vector and sort it and retutn kth element
        // 2 -> Or else do inorder traversal by default will be sorted order then u can elimainate o(nlogn)
       
       int ans = -1;
       int cnt = 0;
        inorder(root,k,ans,cnt);
        return ans;

    }

    void inorder(TreeNode* root,int k,int &ans,int &cnt)
    {

        if(root == NULL || cnt >= k) return;
        
        inorder(root->left,k,ans,cnt);
        cnt++;
        if(cnt==k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right,k,ans,cnt);

        return;

    }
};
