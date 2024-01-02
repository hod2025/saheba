#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int max,min,n;
class max12
{
 int a[100];
public:
  int i,j;
  void get();
  void show();
  void maxmin(int,int,int&,int&);
  void display();
};

void max12::get()
{
  cout<<"\n Enter the size of array:-";
  cin>>n;
  cout<<"\n Enter Elements-";
  for(i=1;i<=n;i++)
  cin>>a[i];
}

void max12::show()
{
  cout<<"\nThe element of array:-\n";
  for(i=1;i<=n;i++)
  {
   if(i%8==0)
   cout<<"\n";
   cout<<a[i]<<"\t";
  }
}

void max12::maxmin(int i,int j,int &max, int &min)
{
  int mid,max1,min1,max2,min2;
  if(i==j)
  {
   max=min=a[i];
  }
  else if(i==j-1)
  {
   //cout<<a[i]<<" "<<a[j];
   if(a[i]<a[j])
   {
    max=a[j];
    min=a[i];
   }
   else
   {
    max=a[i];
    min=a[j];
   }
  }
  else
  {
    mid=(i+j)/2;
    maxmin(i,mid,max1,min1);
    maxmin(mid+1,j,max2,min2);
    max=max1>max2?max1:max2;
    min=min1<min2?min1:min2;
  }
}

void max12::display()
{
 cout<<"\nthe maximum element is -"<<max;
 cout<<"\nthe minimum element is -"<<min;
}

void main()
{
  clrscr();
  cout<<"\n\t***Program max and min element in array***\n\t";
  max12 m;
  clock_t e,s;
  m.get();
  m.show();
  e=clock();
  m.maxmin(1,n,max,min);
  s=clock();
  m.display();
  cout<<"\n The Time Complexity is - "<<(s-e)/CLK_TCK;
  getch();
}
