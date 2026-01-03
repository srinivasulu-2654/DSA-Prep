https://leetcode.com/problems/delete-node-in-a-bst/description/

So here how to approach is :

let's say key = 3

-> first traverse the tree where we can find like root->left->val == key or else root->right->val == key
-> then root->left = key->left
-> key->right = key->extremeright->right

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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key)
        {
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root!=NULL)
        {
            if(root->val > key)
            {
                if(root->left!=NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if(root->right != NULL && root->right->val==key)
                {
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }

            
        }
        return dummy;
    }

        TreeNode* helper(TreeNode* root)
        {
            if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;

            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
           return root->left;
        }

        TreeNode* findLastRight(TreeNode* root)
        {
            if(root->right==NULL) return root;
            return findLastRight(root->right);
        }
    
};
