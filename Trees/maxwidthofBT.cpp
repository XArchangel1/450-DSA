#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    map<int,int> m;
    queue<pair<TreeNode<int> *,int>> q;
    TreeNode<int> *temp = root;
    q.push({temp,0});
    int x = 0;
    while(!q.empty())
    {
        auto it = q.front();
        TreeNode<int> *node = it.first;
        int level = it.second;
        q.pop();
        m[level]++;
        if(node->left)
        {
            q.push({node->left,level+1});
        }
        
        if(node->right)
        {
            q.push({node->right,level+1});
        }
    }
    
    int maxi = INT_MIN;
    for(auto x : m)
    {
        if(maxi < x.second)
        {
            maxi = x.second;
        }
    }
    
    return maxi;
}