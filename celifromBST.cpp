void helper(BinaryTreeNode<int> *node,int x,int &ans)
{
    if(node == NULL)
    {
        return;
    }
    
    if(node->data == x)
    {
        ans = x;
        return;
    }
    
    if(node->data > x)
    {
        ans = node->data;
        helper(node->left,x,ans);
    }
    
    else
    {
        helper(node->right,x,ans);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x)
{   
    int ans = -1;
    helper(node,x,ans);
    return ans;
}