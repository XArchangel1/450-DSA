#include <bits/stdc++.h> 
int length(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    
    return 1+length(head->next);
}

Node *findMiddle(Node *head) 
{
    int l = (length(head))/2;
    Node* temp = head;
    while(l--)
    {
        temp = temp->next;
    }
    
    return temp;
}