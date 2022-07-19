TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
    if(root == NULL)
    {
        return nullptr;
    }
    
    int curr = root->data;
    if(curr < p->data && curr < q->data)
    {
        return LCAinaBST(root->right,p,q);
    }
    
    if(curr > p->data && curr > q->data)
    {
        return LCAinaBST(root->left,p,q);
    }
    
    return root;
}
