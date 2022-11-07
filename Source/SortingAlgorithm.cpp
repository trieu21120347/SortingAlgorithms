#include "Lab03Header.h"

// BUBBLE SORT
// sap xep tang dan

//Comparison Calc
unsigned long long int Bubble_sort(int* a, int n) { // so phan tu n
	unsigned long long int Calc = 1;
	for (int i = 0; Calc++ && i < n - 1; i++) {
		for (int j = 0; Calc++ && j < n - i - 1; j++) {
			if (Calc++ && a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	return Calc - 1;
}

// SELECTION SORT
// sap xep tang dan

//Comparison Calc
unsigned long long int Selection_sort(int* a, int n) {
	unsigned long long int Calc = 1;
	int MinIdx = 0;
	for (int i = 0; Calc++ && i < n - 1; i++) {

		// gan vi tri cua phan tu nho nhat cho i
		MinIdx = i;

		// tim vi tri cua phan tu co gia tri nho nhat tu i+1 den het
		for (int j = i + 1; Calc++ && j < n; j++)
		{
			if (Calc++ && a[MinIdx] >= a[j])
				MinIdx = j;
		}

		// hoan doi phan tu thu i va phan tu nho nhat
		int temp = a[i];
		a[i] = a[MinIdx];
		a[MinIdx] = temp;
	}
	return Calc - 1;
}

// INSERTION SORT
// sap xep tang dan

//Comparison Calc
unsigned long long int Insertion_sort(int* a, int n) {
	unsigned long long int Calc = 1;
	int key, j;
	// chay tu vi tri thu 2 den vi tri cuoi cung
	for (int i = 1; Calc++ && i < n; i++) {

		// gan key cho phan tu i
		key = a[i];

		// j la vi tri cuoi cung cua phan da sap xep
		j = i - 1;

		// so sanh lan luot key voi cac phan tu cua phan da sap xep
		while (Calc++ && key < a[j] && Calc++ && j >= 0) {
			//key< a[j] dam bao tinh on dinh cua day
			a[j + 1] = a[j];
			j--;
		}
		// chen phan tu key vao vi tri chen
		a[j + 1] = key;
	}
	return Calc - 1;
}

// HEAP SORT
// Ham dua cac phan tu ve vi tri dung voi cau truc heap
unsigned long long int heapRebuild(int a[], int pos, int n)
{
	unsigned long long int comp = 0;
	while (2 * pos + 1 < n && ++comp)
	{
		int j = 2 * pos + 1;
		if (j < n - 1 && ++comp) {
			if (a[j] < a[j + 1] && ++comp)
				j = j + 1;
		}
		if (a[pos] >= a[j] && ++comp) {
			return comp;
		}
		swap(a[pos], a[j]);
		pos = j;
	}
	return comp;
}
// Ham xay dung cau truc heap
unsigned long long int heapConstruct(int a[], int n)
{
	unsigned long long int comp = 0;
	for (int i = (n - 1) / 2; ++comp && i >= 0; i--) {
		comp = comp + heapRebuild(a, i, n);
	}
	return comp;
}
// Heap sort
unsigned long long int heapSort(int a[], int n)
{
	unsigned long long int comp = 0;
	comp += heapConstruct(a, n);
	int r = n - 1;
	while (r > 0 && ++comp)
	{
		swap(a[0], a[r]);
		comp += heapRebuild(a, 0, r);
		r--;
	}
	return comp;
}

// MERGE SORT
// Ham chia de tri
// Chia mang ban dau thanh cac mang con sau do sap xep dung thu tu 
// va tron lai thanh mang da sap xep
unsigned long long int merge(int a[], int first, int mid, int last)
{
	// khai báo biến đếm phép so sánh
	unsigned long long int comp = 0;
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int* L = new int[n1];
	int* R = new int[n2];

	// chia mang ben trai
	for (int i = 0; ++comp && i < n1; i++) {
		L[i] = a[first + i];
	}
	// chia mang ben phai
	for (int j = 0; ++comp && j < n2; j++) {
		R[j] = a[mid + j + 1];
	}

	int i = 0;
	int j = 0;
	int k = first;
	// so sanh va sap xep theo dung thu tu
	while (++comp && i < n1 && ++comp && j < n2) {
		a[k++] = (++comp && L[i] < R[j]) ? L[i++] : R[j++];
	}
	// tron 2 mang trai va phai vao mang ban dau
	while (++comp && i < n1) {
		a[k++] = L[i++];
	}
	while (++comp && j < n2) {
		a[k++] = R[j++];
	}
	delete[] L;
	delete[] R;

	return comp;
}
// Ham sap xep tron
unsigned long long int mergeSort(int a[], int first, int last)
{
	unsigned long long int comp = 0;
	if (++comp && first < last) {
		int mid = (first + last) / 2;
		comp += mergeSort(a, first, mid);
		comp += mergeSort(a, mid + 1, last);
		comp += merge(a, first, mid, last);
	}
	return comp;
}

// QUICK SORT
// Ham phan hoach mang ban dau
int partition(int arr[], int l, int h, unsigned long long &comp)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l;++comp && j <= h - 1; j++) {
		if (++comp && arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
unsigned long long int quickSort(int arr[], int l, int h)
{
	unsigned long long int comp = 0;
	// Create an auxiliary stack
	int* stack=new int[h+l-1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (++comp && top >= 0) {
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = partition(arr, l, h,comp);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (++comp && p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (++comp && p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
	return comp;
}
//shaker sort
unsigned long long int ShakerSort(int* a, int n)
{
	unsigned long long int comp = 0;
	int Left = 0;
	int Right = n - 1;
	int k = 0;//k is left_sorted_pos and right_sorted_pos in pseudocode
	while (++comp&& Left < Right)
	{
		//đưa phần tử lớn nhất về cuối
		for (int i = Left; ++comp && i < Right; i++)
		{
			if (++comp && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		//đưa phần tử nhỏ nhất về đầu
		for (int i = Right; ++comp && i > Left; i--)
		{
			if (++comp && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
	return comp;
}
//radix sort
unsigned long long int RadixSort(int* arr, int n)
{
	unsigned long long int comp = 0;
	int i, digitPlace = 1;
	int* result = new int[n];
	int largest = arr[0];
	//tìm phần tử lớn nhất
	for (int i = 1; ++comp && i < n; i++) {
		if (++comp && arr[i] > largest) {
			largest = arr[i];
		}
	}
	//xét duyệt các chữ số từ phải qua
	while (++comp && largest / digitPlace > 0) {
		int count[10] = { 0 };
		//đếm số lượng phần tử mỗi nhóm
		for (i = 0; ++comp && i < n; i++) {
			count[(arr[i] / digitPlace) % 10]++;
		}
		//tính khoảng vị trí các nhóm
		for (i = 1; ++comp && i < 10; i++) {
			count[i] += count[i - 1];
		}
		//copy các nhóm ra dãy kết quả
		for (i = n - 1; ++comp && i >= 0; i--)
		{
			result[count[(arr[i] / digitPlace) % 10] - 1] = arr[i];
			count[(arr[i] / digitPlace) % 10]--;
		}
		//copy lại vào dãy chính
		for (i = 0; ++comp && i < n; i++) {
			arr[i] = result[i];
		}
		digitPlace *= 10;
	}
	delete[]result;
	return comp;
}
//shell sort
unsigned long long int ShellSort(int arr[], int n)
{
	unsigned long long int comp = 0;
	for (int gap = n / 2; ++comp && gap > 0; gap /= 2)
	{
		for (int i = gap; ++comp && i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; ++comp && j >= gap && ++comp && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return comp;
}
unsigned long long int countingSort(int a[], int n)
{
	unsigned long long int comp = 0;
	int max = a[0];
	for (int i = 1; ++comp && i < n; i++)
		if (++comp && a[i] > max)
			max = a[i];

	int* count = new int[max + 1];
	for (int i = 0; ++comp && i <= max; i++)
		count[i] = 0;

	for (int i = 0; ++comp && i < n; i++)
		count[a[i]]++;

	for (int i = 1; ++comp && i <= max; i++)
		count[i] += count[i - 1];

	int* temp = new int[n];
	for (int i = 0; ++comp && i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; ++comp && i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
	return comp;
}

unsigned long long int flashSort(int a[], int n)
{
	unsigned long long int comp = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++comp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		if (++comp && a[i] < minVal)
			minVal = a[i];
		if (++comp && a[i] > a[max])
			max = i;
	}
	if (++comp && a[max] == minVal)
		return comp;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++comp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comp && i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comp && nmove < n - 1)
	{
		while (++comp && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++comp && k < 0) break;
		while (++comp && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	comp += Insertion_sort(a, n);
	return comp;
}
// hàm tính toán thời gian sắp xếp và trả về số phép so sánh
unsigned long long int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size) {
	if (strcmp(argv[pos], "shaker-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = ShakerSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return comp;
	}
	if (strcmp(argv[pos], "radix-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = RadixSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "shell-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = ShellSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "insertion-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = Insertion_sort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "bubble-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = Bubble_sort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "selection-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = Selection_sort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "merge-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = mergeSort(arr, 0, size - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "heap-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = heapSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "quick-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = quickSort(arr, 0, size - 1);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "counting-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = countingSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	if (strcmp(argv[pos], "flash-sort") == 0) {
		clock_t start, end;
		start = clock();
		unsigned long long int comp = flashSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		time *= 1000;
		return comp;
	}
	return 0;
}