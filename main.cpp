#include <iostream>
#include "MyVector.h"
using namespace std;

int main() 
{
	srand(unsigned(time(0)));

	MyVector vect1(10);
	vect1.Init();
	vect1.Print();
	MyVector vect2 = vect1;
	vect2.Print();
	MyVector vect3 = move(vect2);
	vect3.Print();

	for (int i = 0; i < vect1.GetSize(); i++)
	{
		cout << vect1[i] << "\t";
	}
	cout << endl;

	MyVector vect4 = ++vect3;
	vect4.Print();
	MyVector vect5 = --vect4;
	vect4.Print();
	vect5.Print();
}