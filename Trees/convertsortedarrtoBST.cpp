TreeNode<int>* helper(vector<int> &arr,int start,int end)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = helper(arr,start,mid-1);
    root->right = helper(arr,mid+1,end);
    
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    int start = 0;
    int end = n-1;
    return helper(arr,start,end);
}