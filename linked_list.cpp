#include <bits/stdc++.h> 
using namespace std; 
class Node 
{ 
	public: 
	int x,y; 
	Node *next; 
}; 
/*
1>addstart(x,y)
2>delfirst()
3>del(x,y)
4>search(d)
5>search(x,y)
6>length()
*/
int addstart(int a,int b,Node** str)
{
	Node* new_node = new Node();
	Node* temp;
	new_node->x=a;
	new_node->y=b;
	temp=*str;
	new_node->next=temp;
	*str=new_node;
	return 0;
}
void delfirst(Node** str)
{
	Node* temp;
	if(*str==NULL)
		cout<<"no node";
	else
	{
		
		temp=*str;
		*str=temp->next;
		free(temp);

	}

}
void search_d(Node** str,float d)
{
	int a,b;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		a=temp->x;
		b=temp->y;
		if((a*a+b*b)<=(d*d))
		{
			cout<<"("<<a<<","<<b<<")";
		}
		temp=temp->next;
	}
}
bool search(int a,int b,Node** str)
{
	int c,d;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		c=temp->x;
		d=temp->y;
		if(c==a && d==b)
		{
			cout<<"true";
			return true;
		}
	temp=temp->next;	

	}
	if(temp==NULL) {cout<<"false"; return false;}

}
int length(Node** str)
{
	int i=0;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		i++;
		temp=temp->next;
	}
	cout<< i<<"\n";
	return i;
}
 void del(int x,int y,Node** str)
 {
	Node* head=*str;
        if(*str==NULL)
	{ 
		cout<<-1; 
		return;
	}
 	if(head->x==x && head->y==y) 
	{ 
		delfirst(str);
		return;
	}
 	Node *temp=head;
 	Node *prev=NULL;
        int flag=0;
 	while(temp->next!=NULL)
 	{
 		prev=temp;
 		temp=temp->next;
 		if(temp->x==x && temp->y==y) 
 		{
                   prev->next=temp->next;
                   free(temp);
                   flag=1;
                   cout<<0<<"\n"; break;   
 		}
 	}
   if(flag==0) cout<<-1;
   
 }
int main()
{
int i,t,a,b,f;	
float d;
cin >>t;
Node** p;
*p=NULL;
for(i=0;i<t;i++)
{
	cin>> f;
	switch(f)
	{
		case 1:	
			cin >>a;
			cin >>b;
			addstart(a,b,p);
		break;
		case 2:						
			delfirst(p);
		break;
		case 3:
			cin >>a;
			cin >>b;
			del(a,b,p);
		break;
		case 4:
			cin>>d;
			search_d(p,d);
		break;
		case 5:
			cin >>a;
			cin >>b;
			search(a,b,p);
		break;
		case 6:
			length(p);
		break;
		default: cout<< "invalid";
	}
}
return 0;
}
