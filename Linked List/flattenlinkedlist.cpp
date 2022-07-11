#include <bits/stdc++.h>

Node *merger(Node* a,Node *b)
{
    if(a == NULL && b == NULL)
    {
        return nullptr;
    }
    
    if(a == NULL)
    {
        return b;
    }
    
    if(b == NULL)
    {
        return a;
    }
    
    Node *fhead = NULL;
    Node *ftail = NULL;
    if(a->data <= b->data)
    {
        fhead = a;
        ftail = a;
        a = a->child;
    }
    
    else
    {
        fhead = b;
        ftail = b;
        b = b->child;
    }
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data<=b->data)
        {
            ftail->child = a;
            a = a->child;
            ftail = ftail->child;
        }
        
        else
        {
            ftail->child = b;
            b = b->child;
            ftail = ftail->child;
        }
    }
    
    if(a!=NULL)
    {
        ftail->child = a;
    }
    
    if(b!=NULL)
    {
        ftail->child = b;
    }
    fhead->next = NULL;
    return fhead;
}

Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    head->next = flattenLinkedList(head->next);
    head = merger(head,head->next);
    return head;
}
