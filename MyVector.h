#pragma once
class MyVector
{
	int size;
	int* arr;
	
public:
	MyVector();
	MyVector(int s);
	MyVector(const MyVector& obj);
	MyVector(MyVector&& obj) noexcept;
	void Init();
	void Print();
	~MyVector();
	void SetSize(int obj);
	int GetSize() const;
	void SetArr(int obj);
	int GetArr() const;
	void Add(int s, int a);
	int operator[](int index);
	MyVector& operator=(const MyVector& obj);
	MyVector operator=(MyVector&& obj) noexcept;
	MyVector operator++();
	MyVector operator++(int);
	MyVector operator--();
	//MyVector operator--(int);
	void operator() ();
	operator int();
	MyVector operator +=(int obj);
	MyVector operator -=(int obj);
	MyVector operator *=(int obj);
	MyVector operator /=(int obj);

	friend MyVector operator -- (MyVector& obj);
	/*friend istream& operator >> (istream& is, MyVector& obj);*/

	// конструктор копирования, 
	// конструктор переноса, 
	// = с копированием.
	// ++ (добавляет 1 элемент в конец массива, значение = 0), 
	// -- удаляет последний элемент массива
};