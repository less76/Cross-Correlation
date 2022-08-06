
#include "pch.h"
#include <iostream>
using namespace std;

int *const arrange(int *const pointer);

int main()
{

	int x_1[7] = { 5, 6, 7, 1, 2 };  //make same size 
	int h_1[7] = { 6, 7, 1, 4, 3,1 }; //make same size
	
	int x[30];
	int h[30];
	int y[30];

	int size = sizeof(h_1) / sizeof(h_1[0]);
	int size_x = sizeof(x_1) / sizeof(x_1[0]);

	int *here;
	here = (*arrange)(x_1);

	for (int i = 0; i < size_x + 2 * (size_x - 1) - 1; i++) {
		x[i] = *here++;
	}

	here = (*arrange)(h_1);

	for (int i = 0; i < size + 2 * (size - 1) - 1; i++) {
		h[i] = *here++;
	}


	for (int k = 0; k < (size - 1) + (size_x - 1); k++) {
		int hold = 0;
		for (int i = 0; i < size; i++) {
			//cout << h[(size - 1) + i] << endl;
			hold += x[i + k] * h[(size - 1) + i];
		}

		y[k] = hold;
	}

	for (int i = 0; i < (size - 1) + (size_x - 1); i++) {
		cout << y[i] << endl;
	}

	return 0;
}


int *const arrange(int *const pointer) {

	static int val[30];

	int size = 0;
	int n = 0;

	while (n == 0) {
		n = pointer[++size] < -1000 ? 1 : 0;
	}

	for (int i = 0; i < size + 2 * (size - 1); i++) {
		val[i] = 0;
	}

	for (int i = size - 1; i < 2 * size - 1; i++) {
		val[i] = pointer[i - (size - 1)];
	}

	return val;
}