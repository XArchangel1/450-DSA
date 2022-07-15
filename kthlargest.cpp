void help(TreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    help(root->left,ans);
    ans.push_back(root->data);
    help(root->right,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    if(root == NULL || k == 0)
    {
        return -1;
    }
    
    vector<int> arr;
    help(root,arr);
    
    int n = arr.size();
    int ans = n-k;
    if(ans>=0)
    {
       return arr[ans];
    }
    
    else
    {
        return -1;
    }
}
