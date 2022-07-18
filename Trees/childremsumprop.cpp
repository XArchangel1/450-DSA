void changeTree(BinaryTreeNode < int > * root) 
{
    if(root == NULL)
    {
        return;
    }
    
    int child = 0;
    if(root->left)
    {
        child += root->left->data;
    }
    
    if(root->right)
    {
        child += root->right->data;
    }
    
    if(child<root->data)
    {
        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    int update = 0;
    if(root->left)
        update+=root->left->data;
    if(root->right)
        update+=root->right->data;
    
    if(root->left or root->right)
        root->data = update;
}  