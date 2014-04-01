#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

long long int inv_count = 0;

void
merge (int arr[], int start, int mid, int end) 
{
  int h, i, j, k;
  int * b = new int[end - start + 1];
  h = start;
  i = 0;
  j = mid + 1;
  while ((h <= mid) && (j <= end))
  {
     if (arr[h] <= arr[j])
		 {
	  		b[i] = arr[h];
	  		h++;
		 }
  	 else
		 {
	   	 b[i] = arr[j];
	  	 j++;
		 }
     i++;
  }
  while (h <= mid)
  {
     b[i] = arr[h];
     i++;
     h++;
  }
  while (j <= end)
  {
    b[i] = arr[j];
    i++;
    j++;
  }
  for (k = 0; k <= end - start; ++k)
  {
     arr[k + start] = b[k];
  }
  delete[]b;
}


void
merge_sort (int arr[], int start, int end)
{
  if (start < end)
  {
     int mid = (int) (start + end) / 2;
     merge_sort (arr, start, mid);
     merge_sort (arr, mid + 1, end);
     merge (arr, start, mid, end);
  }
} 

int main (int argc, char **argv)
{
  if (argc < 2)
  {
      cout << "Usage : ./a.out no_of_records." << endl;
      cout << "Usage : ./a.out 2000 " << endl;
      exit (-1);
  }
  int maxnum = atoi (argv[1]);
  int *a = new int[maxnum];
  if (!a)
  {
     cout << " Insufficient Memory. " << endl;
     exit (-1);
  }
  int lb = 0, ub = maxnum - 1;
  for (int i = lb; i <= ub; ++i)
  {
     a[i] = rand () % maxnum;
  } 

#ifdef DEBUG
	cout << "Before Sorting..." << endl;
	for (int i = 0; i < maxnum; ++i)
    cout << a[i] << " ";
  cout << endl;
#endif

  
  clock_t start;
  start = clock ();

  merge_sort (a, 0, maxnum - 1);

  start = clock () - start;
  double time_taken = ((double) start) / CLOCKS_PER_SEC;	// in seconds
  cout << "took " << time_taken << " seconds to execute " << endl;

#ifdef DEBUG
	cout << "After Sorting..." << endl;
	for (int i = 0; i < maxnum; ++i)
    cout << a[i] << " ";
  cout << endl;
#endif

	delete []a;

  return 0;
}


