#include "MyVector.h"
#include <ctime>
#include <iostream>
using namespace std;

MyVector::MyVector(): arr(nullptr), size(0)
{
}

MyVector::MyVector(int s): size(s), arr(new int[size])
{
}

MyVector::MyVector(MyVector& obj)
{
	size = obj.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

MyVector::MyVector(MyVector&& obj) noexcept // добавил, потому что ошибка просит поставить noexcept :?
{
	if (obj.arr != nullptr)
	{
		size = obj.size;
		arr = obj.arr;
		obj.size = 0;
		obj.arr = nullptr;
	}
} 

void MyVector::Init()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}

void MyVector::Print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

MyVector::~MyVector()
{
	delete[] arr;
	size = 0;
}

int MyVector::GetSize() const
{
	return size;
}

int MyVector::operator[](int index)
{
	if (index >= 0 && index < size)
	{
		return arr[index];
	}
	return -1;
}

MyVector MyVector::operator=(const MyVector& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	delete[] arr;
	size = obj.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

MyVector MyVector::operator++()
{
	int* newArr = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = 0;
	delete[] arr;
	arr = newArr;
	size++;
	return *this;
}

MyVector MyVector::operator++(int)
{
	MyVector old(*this);
	int* newArr = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = 0;
	delete[] arr;
	arr = newArr;
	size++;
	return old;
}

MyVector MyVector::operator--()
{
	if (size == 0)
	{
		return *this;
	}
	int* newArr = new int[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size--;
	return *this;
}

MyVector MyVector::operator--(int)
{
	MyVector old(*this);
	--(*this);
	return old;
}

MyVector MyVector::operator+=(int)
{
	return MyVector();
}

MyVector MyVector::operator-=(int)
{
	return MyVector();
}

