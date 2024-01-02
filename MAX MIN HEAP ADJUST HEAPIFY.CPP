#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int a[1000],n;

class heap
{
  int i,j,item;
  public:
    void get();
    void show();
    void adjust(int [],int,int);
    void heapify(int [],int);
};

void heap::get()
{
  cout<<"\n Program for Maxheap Using Adjust/heapify:";
  cout<<"\n Enter Array Size:=";
  cin>>n;
  cout<<"\n Enter The Array Element:";
  for(i=1;i<=n;i++)
  cin>>a[i];
}

void heap::show()
{
  cout<<"\n The element is:";
  for(i=1;i<=n;i++)
  cout<<a[i]<<"\t";
  cout<<"\n";
}

void heap::adjust(int a[],int i,int n)
{
  j=2*i;
  int item=a[i];
  while(j<=n)
  {
		
    if((j<n)&&(a[j]<a[j+1])) //(a[j]>a[j+1]) for min heap adjust heapify
    j++;
    if(item>=a[j])// (item<=a[j]) for min heap adjust heapify
    break;
    a[j/2]=a[j];
    j=2*j;
  }
  a[j/2]=item;
}

void heap::heapify(int a[],int n)
{
  for(i=n/2;i>=1;i--)
  adjust(a,i,n);
}

void main()
{
 clrscr();
 clock_t e,s;
 heap h;
 h.get();
 h.show();
 s=clock();
 h.heapify(a,n);
 e=clock();
 h.show();
 cout<<"Time Complexity=>"<<(e-s)/CLK_TCK;
 getch();
}
