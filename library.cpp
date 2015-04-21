#include "library.hpp"

int main( int argc, char **argv )
{
  long m;
  cin >> m;
  cout << endl;
  vector<long> array = random_number<long>(m, 0, 100);
  for ( uli i = 0 ; i < array.size() ; ++i )
	{
	  cout << array[i] << endl;
	}
  cout << endl;
  quick_sort<long>(array, 0, m-1);
  for ( uli t : array )
	{
	  cout << t << endl;
	}
  cout << endl;
  srand((unsigned int)time(NULL));
  long key = array[rand() % m];
  cout << key << endl;
  cout << binary_search3<long>(array, key, 0, m-1) << endl;
  return EXIT_SUCCESS;
}

template<typename T>
T euclid_rest(T m, T n)
{
  if ( m < n ) swap(m, n); 
  if ( n == 0 ) return m; 
  euclid_rest<T>(n, m % n);
  return 777; // dummy
}

template<typename T>
T euclid_sub(T m, T n)
{
  if ( m < n ) swap(m, n);
  if ( m - n == 0 ) return m;
  euclid_sub<T>(n, m - n);
  return 777; // dummy
}

template<typename T>
vector<T> random_number(T n, T min, T max)
{
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 gen(seed);
  uniform_int_distribution<int> dist(min, max);
  vector<T> array(n);
  for ( T i = 0 ; i < n ; ++i )
	{
	  array[i] = dist(gen);
	}
  return array;
}

template<typename T>
void selection_sort(vector<T> &array)
{
  T N = array.size();
  for ( T i = 0 ; i < N - 1 ; i++ )
	{
	  T min_id = i;
	  for ( T j = i + 1 ; j < N ; j++ )
		{
		  if ( array[j] < array[min_id] )
			{
			  min_id = j;
			}
		}
	  swap(array[i], array[min_id]);
	}
}

template<typename T>
void bubble_sort(vector<T> &array)
{
  T N = array.size();
  for ( T i = 0 ; i < N - 1 ; i++ )
	{
	  for ( T j = 1 ; j < N - i ; j++ )
		{
		  if ( array[j] < array[j-1] ) 
			{
			  swap(array[j], array[j-1]);
			}
		}
	}
}

template<typename T>
void insertion_sort(vector<T> &array)
{
  T N = array.size();
  for ( T i = 1 ; i < N ; i++ )
	{
	  T tmp = array[i];
	  T j;
	  for ( j = i ; j > 0 && array[j-1] > tmp ; j-- )
		{
		  array[j] = array[j-1];
		} 
	  array[j] = tmp;
	}
}

template<typename T>
void heap_sort(vector<T> &array)
{
  T i = 0;
  T N = array.size();
  while ( ++i < N )
	{
	  up_heap<T>(array, i);
	}
  while ( --i > 0 )
	{
	  swap(array[0], array[i]);
	  down_heap<T>(array, i);
	}
}

template<typename T>
void up_heap(vector<T> &array, T id_child)
{
  while ( id_child > 0 )
	{
	  T id_parent = (id_child + 1) / 2 - 1; 
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

template<typename T>
void down_heap(vector<T> &array, T n)
{
  T id_parent = 0;
  T tmp = 0;
  
  for(;;)
	{
	  T id_left_child = (id_parent + 1) * 2 - 1;
	  T id_right_child = (id_parent + 1) * 2;
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

template<typename T>
void merge_sort(vector<T> &array, T left, T right)
{
  if ( left >= right ) 
	{
	  return;
	}

  T mid = (left + right) / 2;

  merge_sort<T>(array, left, mid);
  merge_sort<T>(array, mid + 1, right);

  vector<T> tmp(array.size());
  
  T i, j;

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

  for ( T k = left; k <= right; k++ )
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

template<typename T>
void quick_sort(vector<T> &array, T left, T right)
{
  T i = left;
  T j = right;
  T pivot = array[(left+right)/2];

  for(;;) 
	{
	  while ( array[i] < pivot ) i++;
	  while ( array[j] > pivot ) j--;
	  if ( i >= j ) break;
	  swap(array[i], array[j]);
	  i++;
	  j--;
	}
  
  if ( left < i - 1 ) quick_sort<T>(array, left, i - 1);
  if ( j + 1 < right ) quick_sort<T>(array, j + 1, right);
}

template <typename T>
T linear_search(vector<T> &array, T key)
{
  T size = array.size();
  for ( T i = 0 ; i < size ; ++i )
	{
	  if ( array[i] == key )
		{
		  return i;
		}
	}
  return KEY_NOT_FOUND;
}

template<typename T>
T binary_search(vector<T> &array, T key, T min_pos, T max_pos)
{
  while (min_pos <= max_pos)
	{
	  T mid_pos = (min_pos + max_pos) / 2;
	  if (array[mid_pos] < key)
		{
		  min_pos = mid_pos + 1;
		}
	  else if (array[mid_pos] > key)
		{
		  max_pos = mid_pos - 1;
		}
	  else
		{
		  return mid_pos;
		}
	}
  return KEY_NOT_FOUND;
}

template<typename T>
T binary_search2(vector<T> &array, T key, T min_pos, T max_pos)
{
  while (min_pos < max_pos)
	{
	  T mid_pos = (min_pos + max_pos) / 2;
	  if (array[mid_pos] < key) 
		{
		  min_pos = mid_pos + 1;
		}
	  else
		{
		  max_pos = mid_pos;
		}
	}
  if ((min_pos == max_pos) && (array[min_pos] == key))
	{
	  return min_pos;
	}
  else
	{
	  return KEY_NOT_FOUND;
	}
}

template<typename T>
T binary_search3( vector<T> &array, T key, T min_pos, T max_pos )
{
  if ( min_pos <= max_pos )
	{
	  T mid_pos = (min_pos + max_pos) / 2;
	  if ( array[mid_pos] > key )
		{
		  return binary_search3<T>( array, key, min_pos, mid_pos - 1 );
		}
	  else if ( array[mid_pos] < key )
		{
		  return binary_search3<T>( array, key, mid_pos + 1, max_pos);
		}
	  else
		{
		  return mid_pos;
		}
	}
  else
	{
	  return KEY_NOT_FOUND;
	}
}
