#include <bits/stdc++.h>
int length(LinkedListNode<int> *head)
{
    if(head == NULL)
    {
        return 0;
    }
    
    return 1+length(head->next);
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(head == nullptr || k == 0)
    {
        return head;
    }
    int n = length(head);
    int i = 1;
    
    if(n == k)
    {
        return head->next;
    }
    
    LinkedListNode<int> *temp = head;
    while(i<(n-k))
    {
        temp = temp->next;
        i++;
    }
    
    if(temp!=NULL && temp->next!=NULL)
    {
       temp->next = temp->next->next;
    }
    return head;
}