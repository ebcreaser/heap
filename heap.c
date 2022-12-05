#include <stdlib.h>
#include <stdio.h>

static int  _child     (int i);
static int  _parent    (int i);
static void _swap      (int *a, int *b);
static void _heapify   (int *arr, int size, int i);
static void _bubble_up (int *arr, int i);

static int
_child(int i)
{
	return i * 2 + 1;
}

static int
_parent(int i)
{
	return (i - 1) / 2;
}

static void
_swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

static void
_heapify(int *arr, int size, int i)
{
	int largest_ind = i;
	int left_ind = _child(i);
	int right_ind = left_ind + 1;

	if (left_ind < size && arr[left_ind] > arr[largest_ind]) {
		largest_ind = left_ind;
	}
	if (right_ind < size && arr[right_ind] > arr[largest_ind]) {
		largest_ind = right_ind;
	}
	if (largest_ind != i) {
		_swap(arr + i, arr + largest_ind);
		_heapify(arr, size, largest_ind);
	}
}

static void
_bubble_up(int *arr, int i)
{
	int parent_ind = _parent(i);
	if (arr[i] > arr[parent_ind]) {
		_swap(arr + i, arr + parent_ind);
		_bubble_up(arr, parent_ind);
	}
}

void
heap_insert(int *arr, int size, int i, int n)
{
	int parent_ind = _parent(i);
	if (i >= size) {
		return;
	}
	arr[i] = n;
	if (arr[i] > arr[parent_ind]) {
		_bubble_up(arr, i);
	} else {
		_heapify(arr, size, i);
	}
}

void
heap_print(int *arr, int size, int index, int indent) {
	int i;
	int left_index = _child(index);
	int right_index = left_index + 1;

	if (indent > 0) {
		for (i = 0; i < indent; ++i) {
			printf(" ");
		}
		printf("\\");
	}
	printf("%d\n", arr[index]);
	if (left_index < size) {
		heap_print(arr, size, left_index, indent + 1);
	}
	if (right_index < size) {
		heap_print(arr, size, right_index, indent + 1);
	}
}

void
heap_build(int *arr, int size)
{
	int i;

	for (i = _parent(size - 1); i >= 0; --i) {
		_heapify(arr, size, i);
	}
}
