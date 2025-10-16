#include <iostream>
#include "MyVector.h"
using namespace std;

MyVector operator+(int a, MyVector& obj)
{
	MyVector res(obj.GetSize());
	for (int i = 0; i < obj.GetSize(); ++i)
		res.Add(i, a + obj[i]);
	return res;
}

MyVector operator -- (MyVector& obj)
{
	if (obj.GetSize() == 0)
	{
		return *this;
	}
	int* newArr = new int[obj.GetSize() - 1];
	for (size_t i = 0; i < obj.GetSize() - 1; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	obj.GetSize()--;
	return *this;
}

istream& operator >> (istream& is, MyVector& obj)
{
	int a;
	for (int i = 0; i < obj.GetSize(); i++)
	{
		is >> a;
		obj.Add(i, a);
	}
	return is;
}

ostream& operator << (ostream& os, MyVector& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		os << obj[i] << " ";
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
	cout << vect2 << endl;
}