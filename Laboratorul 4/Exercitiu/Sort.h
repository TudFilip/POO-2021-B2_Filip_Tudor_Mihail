#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <STDARG.H>

using namespace std;

class Sort
{
private:
    struct node {
        int info;
        node* prev;
        node* next;
    };
    struct List {
        node* curent;
        node* left;
        node* right;
        node* last;
        node* first;
    };
    List L;

public:
    Sort(int count, int min, int max);
    Sort(int* init);
    Sort(int v[], int count);
    Sort(int count, ...);
    Sort(char* str);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};