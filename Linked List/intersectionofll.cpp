int length(Node *x)
{
	int count = 0;
	while(x!=NULL)
	{
		x = x->next;
		count++;
	}
	
	return count;
}


int findIntersection(Node *firstHead, Node *secondHead)
{
	int l1 = length(firstHead);
	int l2 = length(secondHead);
	
	Node *temp1 = firstHead;
    Node *temp2 = secondHead;
	
	if(firstHead == NULL || secondHead == NULL)
	{
		return -1;
	}
	
	if(l1>l2)
	{
		int difference = l1-l2;
		while(difference--)
		{
			temp1 = temp1->next;
		}
	}
	
	else
	{
		int difference = l2-l1;
		while(difference--)
		{
			temp2 = temp2->next;
		}
	}
	
	while(temp1!=temp2 && temp1->next!=NULL && temp2->next!=NULL)
	{   
       temp1 = temp1->next;
       temp2 = temp2->next;
    }
	
	if(temp1 == temp2)
	{
		return temp1->data;
	}
	
	else
	{
		return -1;
	}
}