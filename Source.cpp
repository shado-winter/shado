using namespace std;
#include<iostream>

int main() {

	double a;
	a = 9.81;

	double* pa = &a;

	//array b
	double b[4];
	b[0] = 1.5;
	b[1] = 3.0;
	b[2] = 5.5;
	b[3] = 7.0;

	//pointer pb
	double* pb = &b[0];

	//pointer pc with 'new'
	double* pc = new double;

	*pc = 3.14;

	double* pd = new double[4];

	pd[0] = 0.5;
	pd[1] = 2.0;
	pd[2] = 4.5;
	pd[3] = 6.0;


	//display
	cout << "Variable\tAddress\t\tValue" << endl;
	cout << "______________________________" << endl;

	cout << "a\t" << &a << "\t" << a << endl;
	cout << "pa\t" << pa << "\t" << *pa << endl;

	for (int i = 0; i < 4; i++) {
		cout << "b[" << i << "]\t" << &b[i] << "\t" << b[i] << endl;
	}

	for (int i = 0; i < 4; i++) {
		cout << "pb[" << i << "]\t" << (pb + i) << "\t" << *(pb + i) << endl;
	}

	cout << "pc\t" << pc << "\t" << *pc << endl;

	for (int i = 0; i < 4; i++) {
		cout << "pd[" << i << "]\t" << (pd + i) << "\t" << *(pd + i) << endl;
	}

	return 0;
}