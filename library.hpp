#include <bits/stdc++.h>

typedef unsigned long long int ulli;
typedef unsigned long int uli;

const int KEY_NOT_FOUND = -1;

using namespace std;

template<typename T>
T euclid_rest(T m, T n);

template<typename T>
T euclid_sub(T m, T n);

template<typename T>
vector<T> random_number(T n, T min, T max);

template<typename T>
void selection_sort(vector<T> &array);

template<typename T>
void bubble_sort(vector<T> &array);

template<typename T>
void insertion_sort(vector<T> &array);

template<typename T>
void heap_sort(vector<T> &array);

template<typename T>
void up_heap(vector<T> &array, T id_child);

template<typename T>
void down_heap(vector<T> &array, T n);

template<typename T>
void merge_sort(vector<T> &array, T left, T right);

template<typename T>
void quick_sort(vector<T> &array, T left, T right);

template<typename T>
T linear_search(vector<T> &array, T key);

template<typename T>
T binary_search(vector<T> &array, T key, T min_pos, T max_pos);

template<typename T>
T binary_search2(vector<T> &array, T key, T min_pos, T max_pos);

template<typename T>
T binary_search3(vector<T> &array, T key, T min_pos, T max_pos);
