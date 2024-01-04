#include"iostream.h"
#include"conio.h"
class path
{
	public:
	int a[10][10],n,i,v1,v2;
	void get()
	{
		cout<<"\n Enter the vertices";
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==-1)
				 a[i][j]=9999;
			}
		}
		for(i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(a[i][j]<(a[i][k]+a[k][j]))
						a[i][j]=a[i][j];
					else
						a[i][j]=a[i][k]+a[k][j];
	}
	void display()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<"\n Enter the source vertex";
		cin>>v1;
		cout<<"\n Enter the destination vertex";
		cin>>v2;
		cout<<"\n shortest path is "<<a[v1][v2];

	}
};
void main()
{
	clrscr();
	path p;
	p.get();
	p.display();
	getch();
}
