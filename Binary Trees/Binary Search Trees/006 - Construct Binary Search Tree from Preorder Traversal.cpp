Here we can solve this in 3 methods:

1) go each and every node and insert where ever we want
2) already given preorder now inorder is the sort of the preorder for BST -> TC : O(nlogn) + O(n) & solve like we did in Binary Tree
3) solve like using Maximum Bound (that we have solved in check wheather it is BST or not)

-> 3rd approach is really brilliant

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return constructBST(preorder,i,INT_MAX);
    }

    TreeNode* constructBST(vector<int>&preorder,int &i,int bound)
    {
        if(preorder.size() == i || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = constructBST(preorder,i,root->val);
        root->right = constructBST(preorder,i,bound);
        return root;
    }
};
