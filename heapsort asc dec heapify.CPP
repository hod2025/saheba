#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int b[5000],n;

class heap
{
  int i,j,item;
  public:
   void get();
   void show();
   void heapsort(int[],int);
   void heapify(int[],int);
   void adjust(int[],int,int);
};

void heap::get()
{
  cout<<"\n Program For HeapSort Using Descending Order:";
  cout<<"\n Enter Size of Array:";
  cin>>n;
  for(i=1;i<=n;i++)
  cin>>b[i];
}

void heap::show()
{
  cout<<"\nThe Elements is:";
  for(i=1;i<=n;i++)
  cout<<b[i]<<"\t";
}

void heap::heapsort(int a[], int n)
{
  heapify(a,n);
  show();
  int t;
  for(i=n;i>=2;i--)
  {
  t=a[i];
  a[i]=a[1];
  a[1]=t;
  adjust(a,1,i-1);
 }
}
void heap::heapify(int a[],int n)
{
  int i;
  for(i=n/2;i>=1;i--)
  adjust(a,i,n);
}

void heap::adjust(int a[], int i,int n)
{
  j=2*i;
  int item=a[i];
  while(j<=n)
  {
  if((j<n)&&(a[j]>a[j+1])) //(a[j]<a[j+1]) for acsending order
  j++;
  if(item<=a[j]) //(item>=a[j]) for ascending order
  break;
  a[j/2]=a[j];
  j=2*j;
  }
  a[j/2]=item;
}

void main()
{
  clrscr();
  clock_t e,s;
  heap h;
  h.get();
  h.show();
  e=clock();
  h.heapsort(b,n);
  s=clock();
  cout<<"\n After Heapsorting:";
  h.show();
  cout<<"\nTime Complexity:"<<(s-e)/CLK_TCK;
  getch();
}
