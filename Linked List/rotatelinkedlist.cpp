#include <bits/stdc++.h> 
Node *rotate(Node *head, int k) {

   if(head==NULL||head->next==NULL||k==0) return head;

   Node * dumy=head;

   int count=1;

   

   while(dumy->next!=NULL){

dumy=dumy->next;

   count++;}

   dumy->next=head;

 k=k%count;

  k=count-k;

 

   while(k--) dumy=dumy->next;

   head=dumy->next;

   dumy->next=NULL;

   return head;

}