void help(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    help(root->left,ans);
    ans.push_back(root->data);
    help(root->right,ans);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{    
    if(root == NULL)
    {
        return false;
    }
    vector<int> arr;
    help(root,arr);
    int i = 0;
    int j = arr.size()-1;
    while(i!=j)
    {
        if(arr[i] + arr[j] == k)
        {
            return true;
        }
        
        else if(arr[i] + arr[j] > k)
        {
            j--;
        }
        
        else
        {
            i++;
        }
    }
    
    return false;
}