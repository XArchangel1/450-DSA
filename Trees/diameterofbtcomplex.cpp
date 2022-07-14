#include<bits/stdc++.h>
int findmax(TreeNode<int> *root,int &maxi)
{
    if(root == nullptr)
    {
        return 0;
    }
    
    int lh = findmax(root->left,maxi);
    int rh = findmax(root->right,maxi);
    maxi = max(maxi,lh+rh);
    
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = INT_MIN;
	findmax(root,maxi);
    return maxi;
}
