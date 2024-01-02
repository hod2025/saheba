

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int n,a[1000];

class q_sort
{
  public:
    void get();
    void show();
    void quick_sort(int,int);
    int partition(int,int);
};

void q_sort::get()
{
  cout<<"\nEnter the Size Of Array:=";
  cin>>n;
   for(int i=1;i<=n;i++)
   {
    cin>>a[i];
   }
}

void q_sort::show()
{
  for(int i=1;i<=n;i++)
  {
   if(i%8==0)
   cout<<"\n";
   cout<<a[i]<<"\t";
  }
}

void q_sort::quick_sort(int p,int q)
{
  int j;
  if(p<q)
  {
    j=partition(p,q);
    quick_sort(p,j-1);
    quick_sort(j+1,q);
  }
}

int q_sort::partition(int m,int p)
{
  int v =a[m];
  int i=m+1;
  int j=p;
  while(i<=j)
  {                 //Descending Order
   while(a[i]<v)   //while(a[i]>v)
   i=i+1;
   while(a[j]>v)  //while(a[j]<v)
   j=j-1;
   if(i<j)
   {
    p=a[i];
    a[i]=a[j];
    a[j]=p;
   }
  }
  a[m]=a[j];
  a[j]=v;
  return j;
}

void main()
{
  clrscr();
  clock_t e,s;
  q_sort q;
  cout<<"\n..Program For  Quick Sort..\n\n";
  q.get();
  cout<<"\n Display the element of array before sort:=\n\n";
  q.show();
  s=clock();
  q.quick_sort(1,n);
  e=clock();
  cout<<"\n Display the element of array after sort :=\n";
  q.show();
  cout<<"\n The Time Complexity :="<<(e-s)/CLK_TCK;
  getch();
}
