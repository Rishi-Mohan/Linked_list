// created_by  Rishi_Mohan

#include<bits/stdc++.h>

#define    ll           long long
#define    db1(x)       cout<<#x<<"="<<x<<'\n'
#define    db2(x,y)     cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define    db3(x,y,z)   cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define    rep(i,n)     for(int i=0;i<(n);++i)
#define    repA(i,a,n)  for(int i=a;i<=(n);++i)
#define    repD(i,a,n)  for(int i=a;i>=(n);--i)

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
       //temp=newNode;
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
    struct node *temp=head,*pre;
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
struct node* Remove_beginning(struct node *head)
{
   struct node* temp = head,*p;
   if(temp==NULL) cout << "empty list" << endl;
   else
   {
       p=temp->next;
       head = p;
       free(temp);
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
struct node* Remove_position(struct node *head , int pos)
{
  struct node* temp=head,*p,*r;
  if(temp==NULL)
  {
      cout << "list is empty" << endl;
  }
  else if(pos==0) head = Remove_beginning(head);
  else
  {
      while(pos>0)
      {
          p=temp;
          temp=temp->next;
          pos--;
          if(temp->next==NULL && pos>0) {cout << "NO position" << endl; return head;}
      }
      if(temp->next==NULL) head = Remove_end(head);
      else
      {
          r=temp->next;
          p->next=r;
          free(temp);
      }
  }
  return head;
}
int search(struct node* head , int val )
{
    struct node *temp = head;
    int ans=-1,i=0;
    while(temp!=NULL)
    {
        if(temp->num==val) {ans=i;break;}
        i++;temp=temp->next;
    }
    return ans;
}
struct node* sorting(struct node* head)
{
   struct node* temp = head;


    while (temp) {
        struct node* minimum = temp;
        struct node* r = temp->next;


        while (r) {
            if (minimum->num > r->num)
                minimum = r;

            r = r->next;
        }


        int x = temp->num;
        temp->num = minimum->num;
        minimum->num = x;
        temp = temp->next;
    }
    return head;
}
struct node* Remove_value(struct node *head,int val)
{
    struct node* temp = head,*p;
    while(temp->num!=val)
    {
        p=temp;
        temp=temp->next;
    }
    p->next = temp->next;
    free(temp);
    return head;
}
void Display(struct node* head)
{
    struct node *temp = head;
	    while(temp!=NULL)
    	{
    		cout << temp->num << " -> " ;
    		temp = temp->next;
    	}
    	//cout << temp->num ;
}

void solve()
{
   struct node *head = NULL ;
   int choice=0,val,pos,k;
   do{
       cout << "\n\n*********************" << endl;
       cout << "1. Create List" << endl;
       cout << "2. Insert at beg" << endl;
       cout << "3. Insert at End" << endl;
       cout << "4. Insert at any position" << endl;
       cout << "5. Remove from beginning" << endl;
       cout << "6. Remove from End" << endl;
       cout << "7. Remove any Position" << endl;
       cout << "8. Search the Element" << endl;
       cout << "9. Sort the list" << endl;
       cout << "10. Remove by value" << endl;
       cout << "11. Display the List" << endl;
       cout << "12. for exit " << endl;
       cout << "*********************" << endl;
       cout << "Enter your choice ......." << endl;
       cin >> choice;
       switch(choice)
       {
        case 1: int t;
                cin >> t;
                while(t--)
                {
                    cin >> val;
                    head = CreateList(head,val);
                }
                break;
        case 2:
               cout << "Enter value: ";
               cin >> val;
               head = addNodeB(head,val);
               break;
        case 3:
               cout << "Enter value: ";
               cin >> val;
               head=addNodeE(head,val);
               break;
        case 4:
               cout << "Enter the position (0 based indexing): ";
               cin >> pos;
               cout << "Enter the Value : ";
               cin >> val;
               head = Insert_position(head,pos,val);
               break;
        case 5:
              head = Remove_beginning(head);
              break;
        case 6:
              head = Remove_end(head);
              break;
        case 7:
              cout << "Enter position(o based indexing) : ";
              cin >> pos;
              head = Remove_position(head,pos);
              break;
        case 8:
              cout << "Enter element " << endl;
              cin >> val;
              k = search(head,val);
              if(k!=-1) cout << "element found at index" << " " << k << endl;
              else cout << "element not exist" << endl;
              break;
        case 9:
             head = sorting(head);
             break;
        case 10:
             cin >> val;
             head = Remove_value(head,val);
             break;
        case 11:
              Display(head);
              break;
        case 12: exit(0);
       }
   }while(choice!=12);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
