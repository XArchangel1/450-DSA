bool validateBST(BinaryTreeNode<int> *root) 
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->left!=NULL)
    {
        if(root->data < root->left->data)
        {
            return false;
        }
    }
    
    if(root->right!=NULL)
    {
        if(root->data > root->right->data)
        {
            return false;
        }
    }
    
    if(validateBST(root->left) and validateBST(root->right))
    {
        return true;
    }
    
    return false;
}