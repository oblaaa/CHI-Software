#pragma once
#include <iostream>

template<typename T, size_t sz>
class List
{
public:
	List();
	~List();
	size_t size()const; 
	const T& operator [] (int index) const;
	void operator +=(const T& el);
private:
	size_t N;
	T* arr;
};

template<typename T, size_t sz>
List<T, sz>::List()
{
	this->arr = new T[sz];
}

template<typename T, size_t sz>
List<T, sz>::~List()
{
	if (this->arr != nullptr)
		delete[] arr;
}

template<typename T, size_t sz>
size_t List<T, sz>::size() const
{
	return N;
}

template<typename T, size_t sz>
const T& List<T, sz>::operator[](int index) const
{
	try
	{
		if (index >= N)
			throw 1;
		else
			return *(arr + index);
	}
	catch (int)
	{
		std::cout << "Out of range! \n";
	}
}

template<typename T, size_t sz>
void List<T, sz>::operator+=(const T& el)
{
	try
	{
		if (N < sz)
		{
			std::cout << sz << std::endl;
			arr[N] = el;
			++N;
		}
		else
			throw 2;
	}
	catch (int)
	{
		std::cout << "Array full! \n";
	}
}

