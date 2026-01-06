https://leetcode.com/problems/binary-search-tree-iterator/description/

So here we have to return next() -> means the next node val in the BST I mean it will be in ascending order right
and hasNext() -> means wheather there is next node or not

Approach 1:

-> So anyway if we traverse through inorder then all the elements will be ascending order
-> so store all ele's in vector
-> then next() means return current element and increase the pointer
-> hasNext() means return if next ele is there in vec return true or false;

TC : O(1) SC : O(N) because we are storing all the elements in vector at a time


class BSTIterator {
public:
    
    vector<int>vec;
    int i = 0;

    BSTIterator(TreeNode* root) {
        pushAllThroughInorder(root);
    }
    
    int next() {
        int val = vec[i];
        i++;
        return val;
    }
    
    bool hasNext() {
        return i<vec.size();
    }

    void pushAllThroughInorder(TreeNode* root)
    {
        if(root==NULL) return;
        pushAllThroughInorder(root->left);
        vec.push_back(root->val);
        pushAllThroughInorder(root->right);

    }
};

Approach 2:

-> So actually the inorder is like this right Left Root Right
-> then extreme left na it will be like ascending only
-> take stack and push all elements of left side
-> next() na return top val and pop and check right is there if there explore all the left values of the right element
-> return true if not empty of stack or else false if empty

TC : O(1) SC : O(H) -> coz we are exploring only all the left element's at a time

class BSTIterator {
public:
    
    stack<TreeNode*>st;

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root)
    {
        for(; root!=NULL; st.push(root),root=root->left);
    }
};


