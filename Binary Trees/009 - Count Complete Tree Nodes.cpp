https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int countNodes(TreeNode* root) {
        
        // the main formula is 2^h - 1 if leftHeight == rightHeight only
       if(root==NULL) return 0;
       int lh = lefHeight(root);
       int rh = rightHeight(root);

       if(lh==rh) return (1<<lh) - 1; // same as 2^h - 1

      return 1 + countNodes(root->left) + countNodes(root->right);

    }

    int lefHeight(TreeNode* root)
    {
        int ht = 0;
        while(root)
        {
            ht++;
            root = root->left;
        }
        return ht;
    }

    int rightHeight(TreeNode* root)
    {
        int ht = 0;
        while(root) {
            ht++;
            root = root->right;
        }
        return ht;
    }
};
