https://www.naukri.com/code360/problems/path-in-a-tree_3843990

This problem is entirely different like we have to print till the give node path

bool check(TreeNode<int>*root,int x,vector<int>&ans)
{
    if(root==NULL) return false;
    
    ans.push_back(root->data);

    if(root->data == x) return true;

    if(check(root->left,x,ans) || check(root->right,x,ans)) return true;

    ans.pop_back();

    return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int>ans;
    check(root,x,ans);
    return ans;
}
