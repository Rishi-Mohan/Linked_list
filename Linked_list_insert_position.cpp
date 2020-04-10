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

struct node* addNodeB(struct node *head,int val)
{
    struct node *newNode = new node();
    newNode->num=val;
    newNode->next = head;
    return newNode;
}

struct node* addNodeE(struct node *head,int val)
{
    struct node *temp=head;
    if(head==NULL)
    {
        struct node* newNode = new node();
        newNode->num = val;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node* newNode = new node();
        newNode->num = val;
        newNode->next= NULL;
        temp->next = newNode;
    }
    return head;
}

struct node* Insert_position(struct node *head,int pos,int val)
{
    struct node* temp = head;
    if(temp==NULL && pos>0)
    {
        cout << "list is Empty" <<endl;
    }
    else if(temp==NULL && pos==0) head = addNodeB(head,val);
    else if(pos==0) head = addNodeB(head,val);
    else
    {
        pos--;
        while(pos>0)
        {
            temp=temp->next;pos--;

            if(temp==NULL && pos!=0) {cout << "Position is not available" << endl;return head;}
        }
        if(temp==NULL && pos==0) head = addNodeE(head,val);
        else
        {
            struct node* newNode = new node();
            newNode->num = val;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
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
    // take the input value and position from user and insert it
    cin >> val >> pos;
    // call the function
    head = Insert_position(head,pos,val);
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
