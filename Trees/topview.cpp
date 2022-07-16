#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) 
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    map<int,int> m;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto it = q.front();
        TreeNode<int> *node = it.first;
        int line = it.second;
        q.pop();
        if(m.count(line) == 0)
        {
            m[line] = node->val;
        }
        
        if(node->left!=NULL)
        {
            q.push({node->left,line-1});
        }
        
        if(node->right!=NULL)
        {
            q.push({node->right,line+1});
        }
    }
    
    for(auto x : m)
    {
        ans.push_back(x.second);
    }
    
    return ans;
}