#include<queue>
void connectNodes(BinaryTreeNode< int > *root) 
{
    if(root == nullptr)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        int s = q.size();
        for(int i = 1;i<=s;i++)
        {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            if(i<s)
            {
                temp->next = q.front();
            }
            
            if(temp->left)
            {
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}