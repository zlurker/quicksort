// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int numbercases[10] = { 302,2392,493,504,27,659,112,20,30,9 };

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quicksort(int rangeStart, int rangeEnd) {
	//cout << endl << "QS group" << endl;
	//for (int i = rangeStart; i <= rangeEnd; i++)
		//cout << numbercases[i] << " ";
	if (rangeEnd - rangeStart < 1)
		return;

	int changeIndex = 0;
	int* pivot = &numbercases[rangeEnd];

	for (int i = 0; i < rangeEnd; i++)
		if (*pivot > numbercases[i]) {
			swap(&numbercases[changeIndex], &numbercases[i]);
			changeIndex++;
		}

	swap(pivot, &numbercases[changeIndex]);
	quicksort(0, changeIndex - 1);
	quicksort(changeIndex + 1, rangeEnd );
}


int main()
{
	quicksort(0, 9);

	for (int i = 0; i < 10; i++)
		cout << numbercases[i] << " ";

	cout << endl;
	system("pause");
	return 0;
}



