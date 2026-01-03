So here in each and every node we have to maintain the intervals of:

[-INT_MIN,INT_MAX]

-> I mean the root val should be in this particular ranges only

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
    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }
    
    bool validate(TreeNode* root, long long minVal,long long maxVal)
    {
        if(root==NULL) return true;

        if(root->val <= minVal || root->val >= maxVal) return false;

        bool left = validate(root->left,minVal,root->val);
        bool right = validate(root->right,root->val,maxVal);

        return left && right;
    }

};
