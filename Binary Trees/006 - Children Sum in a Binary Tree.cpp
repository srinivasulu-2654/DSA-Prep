https://www.geeksforgeeks.org/problems/children-sum-parent/1

/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        
        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;
        
        if(root->data != leftVal + rightVal) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
