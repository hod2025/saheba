#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int p[100];
class heap
{
	int n,a,b,c,no;
public:
	void menu();
	void read_e();
	void s_union(int,int);
	int find(int);
	void print();
};
void heap::menu()
{
	int ch;
	cout<<"...Program for union And find..\n\n";
	cout<<"1:read_ele 2:simple union 3:find 4:print 5:exit"<<endl;
	while(ch!=5)
	{
	switch(ch)
	{
	case 1:
		read_e();
		break;
	case 2:
		cout<<"\n Enter root of two set node:";
		cin>>a>>b;
		s_union(a,b);
		break;
	case 3:
		cout<<"\n Find the node:";
		cin>>no;
		c=find(no);
		cout<<"root node is:";
		cout<<c;
		break;
	case 4:
		print();
		break;
	case 5:
		exit(0);
	}
	cout<<"\n Enter the choice:";
	cin>>ch;
	}
}
void heap::read_e()
{
	cout<<"\n Enter the number of elements:";
	cin>>n;
	cout<<"\n enter elements:";
	for(int i=1;i<=n;i++)
	cin>>p[i];
}
void heap::s_union(int i,int j)
{
	p[i]=j;
}
int heap::find(int i)
{
	while(p[i]>=0)
	{
	i=p[i];
	}
	return i;
}
void heap::print()
{
	cout<<"\n Union of two set:";
	for(int i=1;i<=n;i++)
	{
	cout<<p[i]<<"";
	}
}
void main()
{
	clrscr();
	heap h;
	h.menu();
	getch();
}
