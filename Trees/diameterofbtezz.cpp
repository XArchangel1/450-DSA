#include<bits/stdc++.h>
int findheight(TreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    
    int lh = findheight(root->left);
    int rh = findheight(root->right);
    
    return 1+max(lh,rh);
}

void findmax(TreeNode<int> *root,int &maxi)
{
    if(root == nullptr)
    {
        return;
    }
    
    int lh = findheight(root->left);
    int rh = findheight(root->right);
    maxi = max(maxi,lh+rh);
    
    findmax(root->left,maxi);
    findmax(root->right,maxi);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = INT_MIN;
	findmax(root,maxi);
    return maxi;
}
