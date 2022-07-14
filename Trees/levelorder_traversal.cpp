void help(BinaryTreeNode<int> *root,vector<int> &ans)
{
    queue<BinaryTreeNode<int> *> q;
    if(root == NULL)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root;
    q.push(temp);
    ans.push_back(temp->val);
    while(!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if(front->left)
        {
            ans.push_back(front->left->val);
            q.push(front->left);
        }
        
        if(front->right)
        {
            ans.push_back(front->right->val);
            q.push(front->right);
        }
    }
}

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    help(root,ans);
    return ans;
}