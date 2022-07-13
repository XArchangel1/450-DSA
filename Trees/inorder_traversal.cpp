void getInOrderTraversalhelp(TreeNode *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    getInOrderTraversalhelp(root->left,ans);
    ans.push_back(root->data);
    getInOrderTraversalhelp(root->right,ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    getInOrderTraversalhelp(root,ans);
    return ans;
}