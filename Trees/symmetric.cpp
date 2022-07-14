bool helper(BinaryTreeNode<int>* a, BinaryTreeNode<int>* b)
{
    if(a==NULL && b==NULL)
    {
       return true;
    }
    
    if(a==NULL || b==NULL)
        return false;
    if(a->data!=b->data)
        return false;
    
    return helper(a->left,b->right) && helper(a->right,b->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    if(root==NULL || root->left==NULL && root->right==NULL)
        return true;
    
    return helper(root->left,root->right);
}