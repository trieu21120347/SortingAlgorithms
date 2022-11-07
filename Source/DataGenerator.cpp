#include "Lab03Header.h"
void swap(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

//-------------------------------------------------
int data_order(char* argv[], int pos, string& order) {
	if (strcmp(argv[pos], "-rand") == 0) {
		order = "randomized data";
		return 0;
	}
	if (strcmp(argv[pos], "-nsorted") == 0) {
		order = "nearly sorted data";
		return 3;
	}
	if (strcmp(argv[pos], "-sorted") == 0) {
		order = "sorted data";
		return 1;
	}
	if (strcmp(argv[pos], "-rev") == 0) {
		order = "reverse sorted data";
		return 2;
	}
	return -1;
}


// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void Copy_Array(int* a, int* b, int n) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}
