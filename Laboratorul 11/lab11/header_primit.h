#pragma once
#include<iostream>

using namespace std;

template <class T>
void sortare_cu_erori(T* a, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else {
				if (a[i] == a[j]) {
					a[i] = -1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
