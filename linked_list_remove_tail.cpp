// created_by  Rishi_Mohan

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct node* CreateList(struct node *head,int val)
{
    struct node* temp = head;
	if(head==NULL)
	{
       struct node *newNode = new node();
       newNode->num = val;
       newNode->next = NULL;
       head = newNode;
	}
	else
	{
		struct node *newNode = new node();
		while(temp->next!=NULL) temp=temp->next;
		newNode->num = val;
		newNode->next = NULL;
		temp->next = newNode;
	}
	return head;
}

struct node* Remove_end(struct node *head)
{
  struct node* temp = head,*prev;
  while(temp->next!=NULL)
  {
      prev=temp;
      temp = temp->next;
  }
  prev->next=NULL;
  free(temp);
  return head;
}

void Display(struct node* head)
{
    struct node *temp = head;
	    while(temp!=NULL) // break when the last node encounter
    	{
    		cout << temp->num << " -> " ;
    		temp = temp->next;
    	}

}

void solve()
{
	// initialize head value with NULL
	struct node *head = NULL;
	// create a list having t values
	int t , val , pos;
	cin >> t;
	while(t--)
	{
		cin >> val;
		// call function which create node in the list
		head = CreateList(head,val);
	}
    
    // call the function
    head = Remove_end(head);
    //if multiple times then use while loop
    // call display function
    Display(head);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
