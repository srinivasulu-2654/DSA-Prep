-> Here same like the LCA of BT but there is one slight changes

-> for example root = 5 but nodes p = 7, q = 9

-> then there should be possiblity of both nodes are right or else both are left or else 1 is left and 1 is right

-> so the moment where the p and q are splitting to left and right that is the answer

-> the moment we can't split then that is the answer for example in striver video of example p = 1, q = 2


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr = root->val;
        if(curr<p->val && curr<q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
    }

};
