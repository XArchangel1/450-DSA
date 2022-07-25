bool isLeaf(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return false;
    }
    
    if(root->left == NULL and root->right == NULL)
    {
        return true;
    }
    
    return false;
}

void addLeft(TreeNode<int>* root,vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }
    
    TreeNode<int>* curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
     
        if(curr->left)
        {
            curr = curr->left;
        }
        
        else
        {
            curr = curr->right;
        }
    }
}

void addLeaves(TreeNode<int>* root,vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }
    
    if(isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeaves(root->left,res);
    addLeaves(root->right,res);
}

void addRight(TreeNode<int>* root,vector<int> &res)
{
    if(root == NULL)
    {
        return;
    }
    vector<int> rev;
    TreeNode<int>* curr = root->right;
    while(curr)
    {
        if(!isLeaf(curr))
        {
           rev.push_back(curr->data); 
        }
        
        if(curr->right)
        {
            curr = curr->right;
        }
        
        else
        {
            curr = curr->left;
        }
    }
    
    
    for(int i = rev.size()-1;i>=0;i--)
    {
        res.push_back(rev[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    
    if(!isLeaf(root))
    {
        res.push_back(root->data);
    }
    
    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);
    return res;
}