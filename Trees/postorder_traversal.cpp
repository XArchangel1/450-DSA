void getPostOrderTraversalhelp(TreeNode *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    getPostOrderTraversalhelp(root->left,ans);
    getPostOrderTraversalhelp(root->right,ans);
    ans.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    getPostOrderTraversalhelp(root,ans);
    return ans;
}