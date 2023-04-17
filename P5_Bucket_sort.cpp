// Bhoomika Singh
// program to implemet bucket sort

#include <iostream>  
using namespace std;  
  
// return the maximum element
int getMax(int a[], int n) 
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  

// bucket sort algorithm
void bucket(int a[], int n)  
{  
  int max = getMax(a, n); 
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  

// to print array  
void printArr(int a[], int n)
{  
  for (int i = 0; i < n; ++i)  
    cout<<a[i]<<" ";  
}  

int main()  
{  
  int a[] = {12, 34, 6, 1, 15, 25, 9, 10};  
  int n = sizeof(a) / sizeof(a[0]); 
  
  cout<<"Unsorted array - \n";  
  printArr(a, n);  
  bucket(a, n);  
  cout<<"\n\nSorted array - \n";  
  printArr(a, n);  
}  
