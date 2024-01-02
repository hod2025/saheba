//DAA Program for Binary Search..
#include<iostream.h>
#include<stdlib.h>
#include<time.h>

int a[100];

class binary {
  int i, j, ele, low, mid, high, n;

public:
  void get();
  void show();
  int bsearch(int ele);
  void sort();
};

void binary::get() {
  cout << "\n Enter the array size:";
  cin >> n;
  cout << "\nEnter array elements:";
  for (i = 1; i <= n; i++)
    cin >> a[i];
}

void binary::show() {
  for (i = 1; i <= n; i++)
    cout << a[i] << "\t";
}

int binary::bsearch(int ele) {
  low = 1;
  high = n;
  while (low <= high) {
    mid = (low + high) / 2;
    if (ele < a[mid])
      high = mid - 1; //descending order low = mid + 1
    else if (ele > a[mid])
      low  = mid + 1; //descending order high = mid - 1
    else {
      return mid;
    }
  }
  return -1; // Return -1 if the element is not found
}

void binary::sort() {
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n - 1; j++) {
      if (a[j] > a[j+1]) {   //descending order (a[j]<a[j+1])
	int temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
      }
    }
  }
}

int main() {
  cout << "\n ******Program Binary Search******\n";
  int ele, pos;
  clock_t e, s;
  binary b;
  b.get();
  b.sort();
  cout << "\n Sorted elements are:" << endl;
  b.show();
  cout << "\nEnter the element to be searched:" << endl;
  cin >> ele;
  s = clock();
  pos = b.bsearch(ele);
  if (pos != -1) {
    cout << "Element found at position: " << pos << endl;
  } else {
    cout << "Element not found." << endl;
  }
  e = clock();
  cout << "\n Time Complexity is :-" << ((e - s) / CLOCKS_PER_SEC);
  return 0;
}



