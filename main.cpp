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
	MyVector old(obj);
	if (obj.size == 0)
	{
		return old;
	}
	int* newArr = new int[obj.size - 1];
	for (size_t i = 0; i < obj.size - 1; i++)
	{
		newArr[i] = obj.arr[i];
	}
	delete[] obj.arr;
	obj.arr = newArr;
	obj.size--;
	return old;
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
		os << obj[i] << "\t";
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