/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the number of nodes in the BST.
*/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Reach to the key.
    while (root -> data != key)
    {
        if (key > root -> data)
        {
            predecessor = root -> data;
            root = root -> right;
        }
        else
        {
            successor = root -> data;
            root = root -> left;
        }
    }

    
    BinaryTreeNode<int>* rightSubtree = root -> right;

    while (rightSubtree != NULL)
    {
        successor = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }


    BinaryTreeNode<int>* leftSubtree = root -> left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }

    return {predecessor, successor};
}



/*void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& inorder){
   if(root == NULL){
       return;
   }
   inorderTraversal(root -> left, inorder);
   inorder.push_back(root -> data);
   inorderTraversal(root -> right, inorder);
   return;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
   vector<int> inorder;
   inorderTraversal(root, inorder);
   pair<int,int> ans = make_pair(-1,-1);
   for(int i =0; i< inorder.size(); i++){
       if(inorder[i] == key){
           if(i >=1){
               ans.first = inorder[i-1];
           }
           if(i < inorder.size() -1){
               ans.second = inorder[i+1];
           }
           return ans;
       }
   }
}*/