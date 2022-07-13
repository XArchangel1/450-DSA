void getPreOrderTraversalhelp(TreeNode *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    ans.push_back(root->data);
    getPreOrderTraversalhelp(root->left,ans);
    getPreOrderTraversalhelp(root->right,ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    getPreOrderTraversalhelp(root,ans);
    return ans;
}