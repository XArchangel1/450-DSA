#include <bits/stdc++.h> 
//a contibution
LinkedListNode<int>* reverse(LinkedListNode<int>* head)
{
    if(!head)
    {
        return NULL;
    }
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* post = NULL;
    while(head)
    {
        post = head -> next;
        head -> next = prev;
        prev = head;
        head = post;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) 
{
    if(head == NULL)
    {
        return true;
    }
    
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
   
    LinkedListNode<int> *mid = reverse(slow->next);
    slow->next=NULL;
    LinkedListNode<int> *dummy = head;
    while(mid!=NULL && dummy!=NULL)
    {
        if(mid->data != dummy->data)
        {
           return false;
        }
        
        else
        {
            mid = mid->next;
            dummy = dummy->next;
        }
    }
    
    return true;
}
