#ifndef LAB03HEADER_H
#define LAB03HEADER_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <string.h>
using namespace std;
//template <class T>
void swap(int& a, int& b);
//generate data
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
int data_order(char* argv[], int pos, string& order);
void Copy_Array(int* a, int* b, int n);
//command_line
int line_order(int argv, char* argv2[]);
void Command_line(int argv, char* argv2[]);
void Command_line_1(char* argv[]);
void Command_line_2(char* argv[]);
void Command_line_3(char* argv[]);
void Command_line_4(char* argv[]);
void Command_line_5(char* argv[]);
void write_to_file(string file_name, int* arr, int size);
//sorting algorithm
unsigned long long int Bubble_sort(int* a, int n);
unsigned long long int Selection_sort(int* a, int n);
unsigned long long int Insertion_sort(int* a, int n);
unsigned long long int heapConstruct(int a[], int n);
unsigned long long int heapSort(int a[], int n);
unsigned long long int merge(int a[], int first, int mid, int last);
unsigned long long int mergeSort(int a[], int first, int last);
int partition(int a[], int l, int h,unsigned long long& comp);
unsigned long long int quickSort(int a[], int l, int h);
unsigned long long int ShakerSort(int* a, int n);
unsigned long long int RadixSort(int* arr, int n);
unsigned long long int ShellSort(int arr[], int n);
unsigned long long int countingSort(int a[], int n);
unsigned long long int flashSort(int a[], int n);
unsigned long long int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size);
#endif // !HEADER_H

