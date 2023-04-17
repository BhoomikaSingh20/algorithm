// Bhoomika Singh
// Radix Sort

#include <iostream>
#include <string>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

void print(int ar[], int size, string str) {
  cout << str << "[";
  for (int i = 0; i < size; ++i) {
    cout << (i == 0 ? "" : ", ") << ar[i];
  }
  cout << "]" << endl;
}

void countingSort(int arr[], int size, int k)
{
  int output[size];
  int C[10];

  for (int i = 0; i < 10; ++i)
    C[i] = 0;

  for (int i = 0; i < size; i++)
    C[(arr[i] / k) % 10]++;

  for (int i = 1; i < 10; i++)
    C[i] += C[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[C[(arr[i]/k) % 10] - 1] = arr[i];
    C[(arr[i]/k) % 10]--;
  }

  for (int i = 0; i < size; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int size)
{
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];

  for (int i=1; max/i > 0; i *= 10)
  {
    countingSort(arr, size, i);
    cout << "  Array sorted on the basis of " << i 
	<< (i == 1 ? "st" : "th") << " digit from left:\n";
    print(arr, size, "    ");
  }
}

int main(){ 
  srand(time(0));
  int N = 10;

  for(int i = 0; i < N; i++)
  {
    int size = rand()%15 + 5;
    int *arr = new int[size];
		
    for(int j = 0; j < size; j++)
    {
      arr[j] = rand()%999;
    }
    cout << "Iteration " << i+1 << ":";
    cout << "\n*********************************\n";
    print(arr, size, "\nUnsorted Array = ");
    cout << "\nApplying Radix Sort Algorithm:\n";
    radixSort(arr, size);
    print(arr, size, "\nSorted Array = ");
    cout << endl;
  }

  return 0;
}
