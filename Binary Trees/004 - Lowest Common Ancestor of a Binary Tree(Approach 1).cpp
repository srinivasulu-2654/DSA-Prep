https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
   
   bool findPath(TreeNode* root, TreeNode* x,vector<TreeNode*>&ans)
   {
      if(root==NULL) return false;

      ans.push_back(root);

      if(root==x) return true;

      if(findPath(root->left,x,ans) || findPath(root->right,x,ans)) return true;

      ans.pop_back();

      return false;
   }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1;
        findPath(root,p,ans1);
        vector<TreeNode*>ans2;
        findPath(root,q,ans2);


       TreeNode* LCA = NULL;

        int i = 0, j = 0;
        while(i < ans1.size() && j < ans2.size())
        {
            if(ans1[i] == ans2[j]) {
                LCA = ans1[i];
                i++;
                j++;
            }
            else break;
        }

        return LCA;
    }
};
