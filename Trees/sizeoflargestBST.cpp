#include<bits/stdc++.h>
struct s
{
    bool isBST;
    int mini,maxi,size;
};

s solve(TreeNode<int>* root,int &res)
{
    if(!root)
    {
        return {true,INT_MAX,INT_MIN,0};
    }
    
    auto left = solve(root->left,res);
    auto right = solve(root->right,res);
    
    if(left.isBST && right.isBST && left.maxi<root->data && right.mini>root->data)
    {
        int cur=right.size+left.size+1;
        res=max(res,cur);
        return 
        {true,min(root->data,left.mini),max(root->data,right.maxi),cur};
    }
    
    else 
    { 
        return {false,0,0,0};
    }
    
}

int largestBST(TreeNode<int>* root) 
{
    int res=0;
    solve(root,res);
    return res;
}