#pragma once
class MyVector
{
	int size;
	int* arr;
public:
	MyVector();
	MyVector(int s);
	MyVector(MyVector& obj);
	MyVector(MyVector&& obj) noexcept;
	void Init();
	void Print();
	~MyVector();
	int GetSize() const;
	int operator[](int index);
	MyVector operator=(const MyVector& obj);
	MyVector operator++();
	MyVector operator++(int);
	MyVector operator--();
	MyVector operator--(int);

	void operator() ();
	operator int();

	MyVector operator +=(int);
	MyVector operator -=(int);

	// ����������� �����������, 
	// ����������� ��������, 
	// = � ������������.
	// ++ (��������� 1 ������� � ����� �������, �������� = 0), 
	// -- ������� ��������� ������� �������
};

