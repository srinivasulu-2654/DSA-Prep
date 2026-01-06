Approach - 1:

Normal approach store all the ele's in vec inorder means ascending order
-> take 2 pointers i and j and check wheather the targeted elements is there or not

Tc : O(n) + O(n)
Sc : O(n)

bool findTarget(TreeNode* root, int k) {
        
        vector<int>vec;
        inorder(root,vec);
        int i = 0,j = vec.size()-1;
        while(i<j)
        {
            int target = vec[i]+vec[j];
            if(target > k) j--;
            else if(target < k) i++;
            else return true;
        }
        return false;
    }

    void inorder(TreeNode* root,vector<int>&vec)
    {
        if(root==NULL) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }


Approach 2 : 

Use the concept of BST Iterator of next() we saw next now will implement before also 

next() -> means ascending order will come
before() -> desceding order will come

Tc : O(n) SC:O(H)

