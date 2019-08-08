#include<iostream>
using namespace std;
class Node
{
public:
	int rn;
	Node *link;
};
class icecream
{
private:
	Node *Head;

public:
	icecream()
{
		Head=NULL;

}
	void create();
	void display();
	void Append(Node *Newnode);
	void intersect(icecream B);
	icecream Union(icecream B);
	icecream onlyvanilla(icecream B);
	icecream onlybutterscotch(icecream V);
};
void icecream::create()
{
	char ans;
Node *Newnode;
while(1)
{
	cout<<"Do You Want To Add Node";
	cin>>ans;
	if (ans=='N'||ans=='n')
	break;
	else
	{
	Newnode=new Node;
	cout<<"Enter Roll No";
	cin>>Newnode->rn;
	Newnode->link = NULL;
	Append(Newnode);
	}
}
}
void icecream::Append(Node*Newnode)
{
	if(Head==NULL)
	{
	Head=Newnode;
	}
	else
	{
		Node *temp;
		temp= Head;
		while(temp->link!=NULL)
		{
			temp= temp->link;
		}
		temp->link=Newnode;
	}
}


void icecream::display()
{
	Node *temp=Head;
		if(temp==NULL)
			cout<<"Empty list";
		else
		{ while (temp!= NULL)
			{
				cout<< temp->rn;
				temp=temp->link;
			}
		}
}



void icecream::intersect(icecream B)
		{
	Node *temp,*curr,*newnode;
	icecream I;
	temp=Head;
	while(temp!=NULL)
	{
		curr=B.Head;
		while(curr!=NULL)
		{
			if(temp->rn==curr->rn)
			{
				newnode=new Node;
				newnode->rn=temp->rn;
				cout<<"\nIntersection is=\n";
                newnode->link=NULL;
				I.Append(newnode);
			}
			curr=curr->link;
		}
		temp=temp->link;
	}
	I.display();
		}


icecream icecream::Union(icecream B)
{
	Node *Newnode,*temp,*curr;
	icecream U; int flag;
	temp=Head;
	curr=B.Head;
	while(temp!=NULL)
	{
		Newnode= new Node;
		Newnode->rn=temp->rn;
		Newnode->link=NULL;
		U.Append(Newnode);
		temp=temp->link;
	}
	temp=Head;
	while(curr!=NULL)
	{
		flag=1;
		while(temp!=NULL)
		{
			if(curr->rn==temp->rn)
			{
				flag=0;
				break;
			}
			temp=temp->link;
		}
			if(flag==1)
			{
				Newnode=new Node;
				Newnode->rn=curr->rn;
				cout<<"\n\tUnion is=";
				Newnode->link=NULL;
				U.Append(Newnode);
			}
			curr=curr->link;
		}
		return U;
	}

icecream icecream::onlyvanilla(icecream B)
{
	Node *Newnode,*temp,*curr;
	icecream OV;
	int flag;
	curr=B.Head;
	temp=Head;
	while(temp!=NULL)
	{
		flag=0;
		curr=B.Head;
		while(curr!=NULL)
		{
			if(curr->rn==temp->rn)
			{
				flag=1;
				break;
			}
			curr=curr->link;
		}
			if(flag==0)
			{
				Newnode=new Node;
				Newnode->rn=temp->rn;
				cout<<"\n\tOnly Vanilla:";
				Newnode->link=NULL;
				OV.Append(Newnode);
			}
			temp=temp->link;
		}
		return OV;
}

icecream icecream::onlybutterscotch(icecream V)
{
	Node *Newnode,*temp,*curr;
	icecream OB;
	int flag;
	curr=V.Head;
	temp=Head;
	while(temp!=NULL)
	{
		flag=0;
		curr=V.Head;
		while(curr!=NULL)
		{
			if(curr->rn==temp->rn)
			{
				flag=1;
				break;
			}
			curr=curr->link;
		}
			if(flag==0)
			{
				Newnode=new Node;
				Newnode->rn=temp->rn;
				cout<<"\n\tOnly Butterscotch:";
				Newnode->link=NULL;
				OB.Append(Newnode);
			}
			temp=temp->link;
		}
		return OB;
}





int main()
{
	icecream V,B,r,n,c;
	V.create();
	V.display();
	B.create();
	B.display();
	V.intersect(B);
	r=V.Union(B);
	r.display();
	n=V.onlyvanilla(B);
	n.display();
	c=B.onlybutterscotch(V);
	c.display();
}
