#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int *p, *q, a, b = 10;
	p = (int *)malloc(sizeof(int));
	q = (int *)malloc(sizeof(int));
	a = (5 * b) / 2;
	*p = a + b;
	*q = b;
	q = &b;
	cout << "Nilai a = " << a << endl	   // 25
		 << "Nilai a + b = " << *p << endl // 35
		 << "Nilai q = " << *q;			   // 10
	return 0;
}