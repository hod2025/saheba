
#include<iostream.h>
#include<conio.h>
class dfstree
{
int a[20][20], visited[20],n,i,j;
public:
void dfs(int);
void get();
};
void dfstree::get()
{
cout<<"\nEnter the number of node :- ";
cin>>n;
for(i=1;i<=n;i++)
visited[i]=0;
cout<<"\nEnter the adjancy matrix :- ";
for(i=1;i<=n;i++)
{ for(j=1;j<=n;j++)
cin>>a[i][j];
}
for(i=1;i<=n;i++)
if(visited[i]==0)
dfs(i);
}
void dfstree::dfs(int v)
{
int k;
visited[v]=1;
cout<<"\t"<<v;
for(k=1;k<=n;k++)
if(a[v][k]==1)
if(visited[k]==0)
dfs(k);
}
void main()
{ clrscr();
dfstree d;
d.get();
getch();
}
