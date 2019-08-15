#include <bits/stdc++.h> 
using namespace std; 
class Node 
{ 
	public: 
	int p,q; 
	Node *nept; 
}; 

int addstart(int a,int b,Node** str)
{
	Node* new_node = new Node();
	Node* temp;
	new_node->p=a;
	new_node->q=b;
	temp=*str;
	new_node->nept=temp;
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
		*str=temp->nept;
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
		a=temp->p;
		b=temp->q;
		if((a*a+b*b)<=(d*d))
		{
			cout<<"("<<a<<","<<b<<")";
		}
		temp=temp->nept;
	}
}
bool search(int a,int b,Node** str)
{
	int c,d;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		c=temp->p;
		d=temp->q;
		if(c==a && d==b)
		{
			cout<<"true";
			return true;
		}
	temp=temp->nept;	

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
		temp=temp->nept;
	}
	cout<< i<<"\n";
	return i;
}
 void del(int p,int q,Node** str)
 {
	Node* head=*str;
        if(*str==NULL)
	{ 
		cout<<-1; 
		return;
	}
 	if(head->p==p && head->q==q) 
	{ 
		delfirst(str);
		return;
	}
 	Node *temp=head;
 	Node *prev=NULL;
        int flag=0;
 	while(temp->nept!=NULL)
 	{
 		prev=temp;
 		temp=temp->nept;
 		if(temp->p==p && temp->q==q) 
 		{
                   prev->nept=temp->nept;
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
Node** s;
*s=NULL;
for(i=0;i<t;i++)
{
	cin>> f;
	switch(f)
	{
		case 1:	
			cin >>a;
			cin >>b;
			addstart(a,b,s);
		break;
		case 2:						
			delfirst(s);
		break;
		case 3:
			cin >>a;
			cin >>b;
			del(a,b,s);
		break;
		case 4:
			cin>>d;
			search_d(s,d);
		break;
		case 5:
			cin >>a;
			cin >>b;
			search(a,b,s);
		break;
		case 6:
			length(s);
		break;
		default: cout<< "invalid";
	}
}
return 0;
}
