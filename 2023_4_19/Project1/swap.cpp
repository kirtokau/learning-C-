#include"swap.h"
void swap(int a, int b) {
	int temp = b;
	b = a;
	a = temp;
	cout << "a=" <<a<<endl;
	cout << "b=" <<b<< endl;
}