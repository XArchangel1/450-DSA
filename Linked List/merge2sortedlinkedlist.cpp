#include <bits/stdc++.h> 
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL && second == NULL)
    {
        return NULL;
    }
    
    if(first == NULL)
    {
        return second;
    }
    
    if(second == NULL)
    {
        return first;
    }
    Node<int>* head = NULL;
    Node<int>* ret = NULL;
    
        if(first->data<=second->data)
        {
            head = first;
            ret = head;
            first = first->next;
        }
        
        else
        {
            head = second;
            ret = head;
            second = second->next;
        }
    
    while(first != NULL && second != NULL)
    {
        if(first->data<=second->data)
        {
            head->next = first;
            head = head->next;
            first = first->next;
        }
        
        else
        {
            head->next = second;
            head = head->next;
            second = second->next;
        }
    }
    
    while(first!=NULL)
    {
        head->next = first;
        head = head->next;
        first = first->next;
    }
    
    while(second!=NULL)
    {
        head->next = second;
        head = head->next;
        second = second->next;
    }
    
    return ret;
}
