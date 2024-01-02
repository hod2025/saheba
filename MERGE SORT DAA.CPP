#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int n;


class merge {
  int a[1000], i, j;

public:
  void read();
  void merge_sort(int l, int h);
  void merge1(int l, int m, int h);
  void show();
};

void merge::read()
{
  for (i=0;i<n;i++)
  {
    cin >> a[i];
  }
}

void merge::merge_sort(int l, int h) {
  int m1;
  if (l < h) {
    m1 = int((l + h) / 2);
    merge_sort(l, m1);
    merge_sort(m1 + 1, h);
    merge1(l, m1, h);
  }
}

void merge::merge1(int l, int m, int h) {
  int h1 = l,b[1800];
  int i = l;
  j = m + 1;
  while ((h1 <= m) && (j <= h)) { //for descending
    if (a[h1] <= a[j]) {        //if(a[h1] >= a[j])
      b[i] = a[h1];
      i++;
      h1++;
    } else {
      b[i] = a[j];
      i++;
      j++;
    }
  }
  if (h1 <= m) {
    while (h1 <= m) {
      b[i] = a[h1];
      i++;
      h1++;
    }
  } else {
    while (j <= h) {
      b[i] = a[j];
      i++;
      j++;
    }
  }
  for (int k = l; k <= h; k++)
    a[k] = b[k];
}

void merge::show() {
  for (i = 0; i < n; i++) {
    cout << a[i] << "\t";
    if ((i + 1) % 9 == 0)
      cout << endl;
  }
}

void main()
{
  clrscr();
  clock_t s, e;
  int l, h;
  merge m;
  cout << "Program for Merge Sort...\n\n";
  cout << "Enter the element:";
  cin >> n;
  h = n - 1;
  l = 0;
  m.read();
  cout << "\n\nDisplay the Array Element=\n\n";
  m.show();
  s = clock();
  m.merge_sort(l, h);
  e = clock();
  cout << "\nAfter Sorting=\n";
  m.show();
  cout << "\nTime Complexity is =" << ((e - s)/CLK_TCK);
  getch();
}



