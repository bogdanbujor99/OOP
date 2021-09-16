#pragma once
#include<exception>
#include"Compare.h"
using namespace std;
class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index prea mare!";
	}
};

template<class T>
class ArrayIterator {
public:
	int current;
	T** p;
	ArrayIterator() {
	    current = 0;
	}
	ArrayIterator(T** pointer)
	{
		this->p = pointer;
		this->current = 0;
	}
	ArrayIterator& operator ++ () {
		ArrayIterator<T>it = *this;
		p++;
		return it;
	}
	ArrayIterator& operator--  () {
		ArrayIterator<T>it = *this;
		p--;
		return it;
	}
	bool operator= (ArrayIterator<T>& a) {
		return(p == a.p);
	}
	bool operator!= (ArrayIterator<T>& a) {
		return (p != a.p);
	}
	T* GetElement() {
		return p[0];
	}
};

template<class T>
class Array
{
public:
	T**List;
	int capacity;
	int size;
//public:
	Array() {
		capacity = size = 0;
	}
	Array(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->List = (T**)(malloc(capacity * sizeof(T*)));
		for (int i = 0; i < capacity; i++) {
			List[i] = (T*)malloc(sizeof(T));
		}
	}
	Array(const Array<T>& otherArray) {
		this->capacity = otherArray.capacity;
		this->size = otherArray.size;
		this->List = (T**)(malloc(capacity * sizeof(T*)));
		for (int i = 0; i < capacity; i++) {
			List[i] = (T*)malloc(sizeof(T));
		}
		for (int i = 0; i <= otherArray.size; i++) {
			this->List[i] = otherArray.List[i];
		}
	}
	T& operator[](int index) {
		exceptie1 Big;
		try {
			if (index > size)
				throw Big;
			return *List[index];

		}
		catch (exception& e) {
			cout << "Exceptie:" << e.what() << endl;
		}
	}
	const Array<T>& operator+=(const T& newElem) {
		List[size] = new T;
		*List[size] = newElem;
		size++;
		return (*this);
	}
	const Array<T>& Insert(int index, const T& newElem) {
		exceptie1 Big;
		try {
			if (index >= size || index>capacity)
				throw Big;
			*List[index] = newElem;
			return (*this);

		}
		catch (exception& e) {
			cout << "Exceptie:" << e.what() << endl;
		}
	}
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		exceptie1 Big;
		try {
			if (index > size || index>capacity)
				throw Big;
			for (int i = 0; i <= otherArray.size; i++) {
				List[index] = *otherArray.List;
			}
			return (*this);

		}
		catch (exception& e) {
			cout << "Exceptie:" << e.what() << endl;
		}
	}
	bool operator=(const Array<T>& otherArray) {
		this->capacity = otherArray.capacity;
		this->size = otherArray.size;
		this->List = (T**)(malloc(capacity * sizeof(T*)));
		for (int i = 0; i < capacity; i++) {
			List[i] = (T*)malloc(sizeof(T));
		}
		for (int i = 0; i <= otherArray.size; i++) {
			this->List[i] = otherArray.List[i];
		}
		return true;
	}
	const Array<T>& Delete(int index) {
		exceptie1 Big;
		try {
			if (index > size || index > capacity)
				throw Big;
			for (int i = index; i <= size - 1; i++)
				List[i] = List[i + 1];

		}
		catch (exception& e) {
			cout << "Exceptie:" << e.what() << endl;
		}
	}
	void Sort() {
		for (int i = 0; i <= size - 2; i++)
			for (int j = i + 1; j <= size - 1; j++)
				if (*List[i] > * List[j])swap(List[i], List[j]);
	}
	void Sort(int(*compare)(const T&, const T&)) {
		for (int i = 0; i <= size - 2; i++)
			for (int j = i + 1; j <= size - 1; j++)
				if (compare(*List[i], *List[j]) == 1)swap(List[i], List[j]);
	}
	void Sort(Compare *comparator) {
		for (int i = 0; i <= size - 2; i++)
			for (int j = i + 1; j <= size - 1; j++)
				if (comparator->CompareElements((void*)*List[i], (void*)*List[j]) == 1)swap(List[i], List[j]);
	}
	int BinarySearch(const T& elem) {
		int l, r, m;
		l = 0;
		r = size-1 ;
		while (r >= l) {
			m = (l + r) / 2;
			if (*List[m] == elem)
				return m;
			if (*List[m] > elem)r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int l, r, m;
		l = 0;
		r = size - 1;
		while (r >= l) {
			m = (l + r) / 2;
			if (compare(*List[m], elem) == 0)
				return m;
			else if (compare(*List[m], elem)==1)r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator) {
		int l, r, m;
		l = 0;
		r = size - 1;
		while (r >= l) {
			m = (l + r) / 2;
			if (comparator->CompareElements( (void*)*List[m], (void*)elem)==0)
				return m;
			if (comparator->CompareElements((void*)*List[m], (void*)elem) == 1)r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
	int Find( const T& elem ) {
		for (int i = 0; i <= size - 1; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i <= size - 1; i++)
			if (compare(*List[i],elem)==0)
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i <= size - 1; i++)
			if (comparator->CompareElements((void*)*List[i], (void*)elem) == 0)
				return i;
		return -1;
	}
	int GetSize() {
		return size;
	}
	int GetCapacity(){
		return capacity;
	}
	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> myIt(&List[0]);
		return myIt;
		
	}
	ArrayIterator<T> GetEndIterator() {
		ArrayIterator<T> myIt(&List[size]);
		return myIt;
	}
	void Print() {
		for (int i = 0; i <= size-1; i++)
			cout << *List[i];
	}
};
