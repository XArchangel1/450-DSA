void inorder(BinaryTreeNode<int>* root, vector<BinaryTreeNode<int>*> &v)
{
    if(root)
    {
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<BinaryTreeNode<int>*> v;
    inorder(root, v);
    v[0]->left=NULL;
    v[0]->right=v[1];
    v[v.size()-1]->left=v[v.size()-2];
    v[v.size()-1]->right=NULL;
    for(int i=1; i<v.size()-1; i++)
    {
        v[i]->left=v[i-1];
        v[i]->right=v[i+1];
    }
    return v[0];
}