https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void f(Node* root,vector<int>&temp,vector<vector<int>>&ans)
  {
      temp.push_back(root->data);
      
      if(root->left == NULL && root->right == NULL)
      {
          ans.push_back(temp);
      }
      
      if(root->left != NULL) f(root->left,temp,ans);
      if(root->right!=NULL) f(root->right,temp,ans);
      
      temp.pop_back();
      
  }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        f(root,temp,ans);
        return ans;
    }
};
