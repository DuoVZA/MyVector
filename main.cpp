#include <iostream>
#include "MyVector.h"
using namespace std;

//MyVector operator+(int a, MyVector obj)
//{
//	MyVector res;
//	for (size_t i = 0; i < obj.GetSize(); i++)
//	{
//		res[i] = a + obj[i];
//	}
//	return res;
//}

istream& operator >> (istream& is, MyVector& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		cout << "Arr " << i + 1 << ": ";
		is >> obj.arr[i];
	}
	return is;
}

ostream& operator << (ostream& os, MyVector& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj[i];
	}
	return os;
}

int main() 
{
	srand(unsigned(time(0)));

	MyVector vect1(10);
	vect1.Init();
	MyVector vect2 = 10 + vect1;
	vect1.Print();
	vect2.Print();

	cin >> vect2;
}