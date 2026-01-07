https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

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

   long long mod = 1e9+7;
   int sum = 0;
   long long maxProd = 0;

    int maxProduct(TreeNode* root) {
        
        if(root==NULL) return 0;
        maxProd = 0;
        sum = totalSum(root);
        rootSum(root);
        return maxProd % mod;
    }

    int totalSum(TreeNode* root)
    {
       if(root==NULL) return 0;
       int leftSum = totalSum(root->left);
       int rightSum = totalSum(root->right);
       return root->val + leftSum + rightSum;
    }

    int rootSum(TreeNode* root)
    {
        if(root==NULL) return 0;

      int leftSum =  rootSum(root->left);
      int rightSum =  rootSum(root->right);

       long long subTreeSum = root->val + leftSum + rightSum;

       long long remainingSum = sum - subTreeSum;

       maxProd = max(maxProd,subTreeSum * remainingSum);

      return subTreeSum;


    }
};
