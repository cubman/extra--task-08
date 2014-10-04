#include <iostream>

#include <cstdlib>
#include<cassert>
#include<ctime>

using std::rand;
using std::swap;

void print_array(int const * arr, int size, char delim = ' ') {
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << delim;
	std::cout << std::endl;
}

// pivot - "�������" �������
// partition - ����������������� �������� ����� �������,
// �������� �������� [left, right), ��� ��� � ������
// ������� �������� ������� pivot, � � ����� - �������;
// ���������� ����� ������ ����� ���������, ������� pivot;
int * partition(int * left, int *  right, int * pivot) 
{
	int * store = left; // ����� ��� ������� ���������, ������� pivot
	int pivotValue = *pivot;

	swap(*pivot, *right); 

	for (int * p = left; p != right; ++p)
		if (*p < pivotValue)
			swap(*p, *store++);

	swap(*store, *right); 

	return store;
}

const int q = 7;
void my_qsort(int * arr, int n) {
	if (n <= 1)
		return; // ������ � 1 ��� 0 ��������� ��� ����������

	int * pivotPtr = arr + rand() % n; // ��������� ����� �������� �������� 
	int newPivotIdx = partition(arr, arr + n - 1, pivotPtr) - arr;

	my_qsort(arr, newPivotIdx); 
	my_qsort(arr + newPivotIdx + 1, n - newPivotIdx - 1); 
}


int main()
{
	int a[] = { 5, 12, 19, 12, 4, 9, -1 };
	my_qsort(a, q);

	assert(a[0] == -1);
	assert(a[1] == 4);
	assert(a[2] == 5);
	assert(a[3] == 9);
	assert(a[4] == 12);
	assert(a[5] == 12);
	assert(a[6] == 19);

	print_array(a, q);
}