#include <bits/stdc++.h>

typedef unsigned long long int ulli;

using namespace std;

ulli euclid(ulli m, ulli n);
ulli euclid2(ulli m, ulli n);
void my_swap(long &m, long &n);
vector<long> random_number(long n, long min, long max);
void selection_sort(vector<long> &array);
void bubble_sort(vector<long> &array);
void insertion_sort(vector<long> &array);
void heap_sort(vector<long> &array);
void up_heap(vector<long> &array, int id_child);
void down_heap(vector<long> &array, int n);
void merge_sort(vector<long> &array, int left, int right);
void quick_sort(vector<long> &array, int left, int right);

int main( int argc, char **argv )
{
  int m;
  cin >> m;
  cout << endl;
  vector<long> array = random_number(m, 0, 100);
  for ( uint i = 0 ; i < array.size() ; ++i )
	{
	  cout << array[i] << endl;
	}
  cout << endl;
  quick_sort(array, 0, m-1);
  for ( uint i = 0 ; i < array.size() ; ++i )
	{
	  cout << array[i] << endl;
	}
  return EXIT_SUCCESS;
}

ulli euclid(ulli m, ulli n)
{
  if ( m < n ) { swap(m, n); }
  if ( n == 0 ) { return m; }
  euclid(n, m % n);
  return 777; // dummy
}

ulli euclid2(ulli m, ulli n)
{
  if ( m < n ) { swap(m, n); }
  if ( m - n == 0 ) { return m; }
  euclid2(n, m - n);
  return 777; // dummy
}

void my_swap(long &m, long &n)
{
  long t;
  t = m;
  m = n;
  n = t;
}

vector<long> random_number(long n, long min, long max)
{
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 gen(seed);
  uniform_int_distribution<int> dist(min, max);
  vector<long> array(n);
  for ( long i = 0 ; i < n ; ++i )
	{
	  array[i] = dist(gen);
	}
  return array;
}

void selection_sort(vector<long> &array)
{
  uint N = array.size();
  for ( uint i = 0 ; i < N - 1 ; i++ )
	{
	  uint min_id = i;
	  for ( uint j = i + 1 ; j < N ; j++ )
		{
		  if ( array[j] < array[min_id] )
			{
			  min_id = j;
			}
		}
	  swap(array[i], array[min_id]);
	}
}

void bubble_sort(vector<long> &array)
{
  uint N = array.size();
  for ( uint i = 0 ; i < N - 1 ; i++ )
	{
	  for ( uint j = 1 ; j < N - i ; j++ )
		{
		  if ( array[j] < array[j-1] ) 
			{
			  swap(array[j], array[j-1]);
			}
		}
	}
}

void insertion_sort(vector<long> &array)
{
  uint N = array.size();
  for ( uint i = 1 ; i < N ; i++ )
	{
	  int tmp = array[i];
	  uint j;
	  for ( j = i ; j > 0 && array[j-1] > tmp ; j-- )
		{
		  array[j] = array[j-1];
		} 
	  array[j] = tmp;
	}
}

void heap_sort(vector<long> &array)
{
  int i = 0;
  int N = array.size();
  while ( ++i < N )
	{
	  up_heap(array, i);
	}
  while ( --i > 0 )
	{
	  swap(array[0], array[i]);
	  down_heap(array, i);
	}
}

void up_heap(vector<long> &array, int id_child)
{
  while ( id_child > 0 )
	{
	  int id_parent = (id_child + 1) / 2 - 1; 
	  if ( array[id_parent] < array[id_child] ) 
		{
		  swap(array[id_parent], array[id_child]);
		}
	  else
		{
		  break;
		}
	  id_child = id_parent;
	}
}

void down_heap(vector<long> &array, int n)
{
  int id_parent = 0;
  int tmp = 0;
  
  for(;;)
	{
	  int id_left_child = (id_parent + 1) * 2 - 1;
	  int id_right_child = (id_parent + 1) * 2;
	  if ( id_left_child >= n )
		{
		  break;
		}
	  if ( array[id_left_child] > array[tmp] )
		{
		  tmp = id_left_child;
		}
	  if ( (id_right_child < n) && (array[id_right_child] > array[tmp]) )
		{
		  tmp = id_right_child;
		}
	  if ( tmp == id_parent )
		{
		  break;
		}
	  swap(array[tmp], array[id_parent]);
	  id_parent = tmp;
	}
}

void merge_sort(vector<long> &array, int left, int right)
{
  if ( left >= right ) 
	{
	  return;
	}

  int mid = (left + right) / 2;

  merge_sort(array, left, mid);
  merge_sort(array, mid + 1, right);

  vector<long> tmp(array.size());
  
  int i, j;

  for ( i = left; i <= mid; i++ )
	{
	  tmp[i] = array[i];
	}
  for( i = mid + 1, j = right; i <= right; i++, j-- )
	{
	  tmp[i] = array[j];
	}

  i = left;
  j = right;

  for ( int k = left; k <= right; k++ )
	{
	  if ( tmp[i] <= tmp[j] )
		{
		  array[k] = tmp[i++];
		}
	  else
		{
		  array[k] = tmp[j--];
		}
	}  
}

void quick_sort(vector<long> &array, int left, int right)
{
  int i = left;
  int j = right;
  int pivot = array[(left+right)/2];

  for(;;) 
	{
	  while ( array[i] < pivot ) i++;
	  while ( array[j] > pivot ) j--;
	  if ( i >= j ) break;
	  swap(array[i], array[j]);
	  i++;
	  j--;
	}
  
  if ( left < i - 1 ) quick_sort(array, left, i - 1);
  if ( j + 1 < right ) quick_sort(array, j + 1, right);
}
