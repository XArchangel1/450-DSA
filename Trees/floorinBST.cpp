void helper(TreeNode<int> * root,int X,int &ans)
{
    if(root == NULL || X == 0)
    {
        return;
    }
    
    if(root->val == X)
    {
        ans = root->val;
    }
    
    else if(root->val > X)
    {
        if(root->left)
        {
            helper(root->left,X,ans);
        }
        
        else
        {
            return;
        }
    }
    
    else
    {
        ans = root->val;
        
        if(root->right)
        {
            helper(root->right,X,ans);
        }
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = 0;
    helper(root,X,ans);
    return ans;
}