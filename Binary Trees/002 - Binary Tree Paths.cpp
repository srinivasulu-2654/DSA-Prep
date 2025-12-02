https://leetcode.com/problems/binary-tree-paths/description/

Here not passing reference passing by value so at every node the parent thing will remain unchanged so no need to backtrack 

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
   
   void f(TreeNode* root,string currPath,vector<string>&ans)
   {
       if(root->left == NULL && root->right == NULL)
       {
          currPath += to_string(root->val);
          ans.push_back(currPath);
       }

       string curr = to_string(root->val) + "->";
       if(root->left != NULL) f(root->left,currPath + curr,ans);
       if(root->right != NULL) f(root->right,currPath + curr,ans);
   }

    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        f(root,"",ans);
        return ans;
    }


};
