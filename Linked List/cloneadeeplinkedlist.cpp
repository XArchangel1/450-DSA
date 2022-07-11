#include <bits/stdc++.h>
/*LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
        unordered_map<LinkedListNode<int>*, LinkedListNode<int>*>mp;
        if(head == NULL){
            return head;
        }
        
        LinkedListNode<int> *temp = head;
        while(temp){
            mp[temp] = new LinkedListNode<int>(temp -> data);
            temp = temp -> next;
        }
        
        temp = head;
        while(temp){
            mp[temp] -> next = mp[temp -> next];
            mp[temp] -> random = mp[temp -> random];
            temp = temp -> next;
        }
        
        return mp[head];
}
*/
//Second Approach
#include <bits/stdc++.h>
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{    
        if(head == NULL){
            return head;
        }
        LinkedListNode<int> *temp = head;
        while(temp != NULL){
            LinkedListNode<int> *newnode = new LinkedListNode<int>(temp->data);
            newnode -> next = temp -> next;
            temp -> next = newnode;
            temp = newnode -> next;
        }
        
        temp = head;
        while(temp != NULL){ 
            if(temp -> random == NULL){
                temp -> next -> random = NULL;
            }
            else{
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        
        LinkedListNode<int> *main = head;
        temp = head;
        LinkedListNode<int> *ans = head -> next;
        LinkedListNode<int> *temp2 = ans;
        
        while(temp != NULL){
            temp -> next = temp2 -> next;
            temp = temp -> next;
            if(temp2 -> next == NULL){
                temp2 -> next = NULL;
            }
            else{
                temp2 -> next = temp2 -> next -> next;
            }
            temp2 = temp2 -> next;
        }
        return ans;
}