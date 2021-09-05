#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
struct Node 
{ 
    int data; 
    Node *next, *prev; 
    Node(int x)
    {
        data = x;
        prev=NULL;
        next = NULL;
    }
};
int main()
{
	fast();
	int i,n,k,co=0,v;
	Node *a,*head=NULL,*c,*p,*nx,*pr;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>v;
		if(head==NULL)
		{
			a=new Node(v);
			head=a;
		}
		else
		{
			Node *b=new Node(v);
			b->prev=a;
	        a->next=b;
			a=a->next;
		}
	}
	cin>>k;
	p=NULL;
	pr=head;
	c=head;
	while(c!=NULL&&co!=k)
	{
		nx=c->next;
		c->next=p;
		if(p!=NULL)
			p->prev=c;
		p=c;
		c=nx;
		co++;
	}
	head=p;
	head->prev=NULL;
	Node *pre;
	while(c!=NULL)
	{
		pre=c;
		p=c;
		co=1;
		c=c->next;
	    while(c!=NULL&&co!=k)
	    {
		    nx=c->next;
		    c->next=p;
		    p->prev=c;
		    p=c;
		    c=nx;
		    co++;
	    }
	    pr->next=p;
	    p->prev=pr;
	    pr=pre;
	}
	pr->next=NULL;
	cout<<"Reverse Doubly Linked List in groups of "<<k<<" :- ";
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		p=head;
		head=head->next;
	}
	// cout<<"\n";
	// while(p!=NULL)
	// {
	// 	cout<<p->data<<" ";
	// 	p=p->prev;
	// }
	return 0;
}