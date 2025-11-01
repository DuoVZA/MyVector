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

MyVector::MyVector(const MyVector& obj)
{
	try
	{
		if (obj.size <= 0)
		{
			throw "Error! Size <= 0";
		}
		size = obj.size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i>=size)
			{
				throw "Error! To much!";
			}
			arr[i] = obj.arr[i];
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

MyVector::MyVector(MyVector&& obj) noexcept // добавил, потому что ошибка просит поставить noexcept :?
{
	try
	{
		if (obj.size <= 0)
		{
			throw "Error! Size <= 0";
		}
		size = obj.size;
		arr = obj.arr;
		obj.size = 0;
		obj.arr = nullptr;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
} 

void MyVector::Init()
{
	try
	{
		if (size <= 0)
		{
			throw "Error! No array!";
		}
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 50;
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

void MyVector::Print()
{
	try
	{
		if (size <= 0)
		{
			throw "Error! No array!";
		}
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

MyVector::~MyVector()
{
	delete[] arr;
	size = 0;
}

void MyVector::SetSize(int obj)
{
	size = obj;
}

int MyVector::GetSize() const
{
	return size;
}

void MyVector::SetArr(int obj)
{
	if (size < 0)
		return;
	*arr = obj;
}

int MyVector::GetArr() const
{
	return *arr;
}

void MyVector::Add(int s, int a)
{
	arr[s] = a;
}

int MyVector::operator[](int i)
{
	if (i >= 0 && i < size)
	{
		return arr[i];
	}
	return -1;
}

MyVector& MyVector::operator=(const MyVector& obj)
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

MyVector MyVector::operator=(MyVector&& obj) noexcept
{
	size = obj.size;
	arr = obj.arr;
	obj.size = 0;
	obj.arr = nullptr;
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

//MyVector MyVector::operator--(int)
//{
//	MyVector old(*this);
//	--(*this);
//	return old;
//}

void MyVector::operator() ()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

MyVector::operator int()
{
	return size;
}

MyVector MyVector::operator+=(int obj)
{
	int* newArr = new int[size + obj];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	for (size_t i = size; i < size+obj; i++)
	{
		newArr[i] = 0;
	}
	delete[] arr;
	arr = newArr;
	size += obj;
	return *this;
}

MyVector MyVector::operator-=(int obj)
{
	if (size == 0)
	{
		return *this;
	}
	else if (size<obj)
	{
		return *this;
	}
	int* newArr = new int[size - obj];
	for (size_t i = 0; i < size - obj; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size -= obj;
	return *this;
}

MyVector MyVector::operator*=(int obj)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] *= obj;
	}
	return *this;
}

MyVector MyVector::operator/=(int obj)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > obj)
		{
			arr[i] /= obj;
		}
	}
	return *this;
}
