void getInOrderTraversalhelp(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    getInOrderTraversalhelp(root->left,ans);
    ans.push_back(root->data);
    getInOrderTraversalhelp(root->right,ans);
}

void getPreOrderTraversalhelp(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    ans.push_back(root->data);
    getPreOrderTraversalhelp(root->left,ans);
    getPreOrderTraversalhelp(root->right,ans);
}

void getPostOrderTraversalhelp(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    getPostOrderTraversalhelp(root->left,ans);
    getPostOrderTraversalhelp(root->right,ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    
    vector<int> in;
    vector<int> pre;
    vector<int> post;
    
    getInOrderTraversalhelp(root,in);
    getPreOrderTraversalhelp(root,pre);
    getPostOrderTraversalhelp(root,post);
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    return ans;
}