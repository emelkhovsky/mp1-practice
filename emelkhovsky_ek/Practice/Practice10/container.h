#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include "iostream"
#include "exceptions.h"
using namespace std;
template <typename T, int maxsize>
class container {
private:
	T* a;
	int count;
public:
	container();
	container(const container&);
	container(T*, int);
	~container();

	bool full();
	bool empty();

	int search(T);
	void add(const T);
	void del(T);

	T& operator[](int);
	const T& operator[](int)const;

	friend ostream& operator<<(ostream& out, const container& arr) {
		if (arr.count == 0) {
			out << "The container is empty";
			return out;
		}
		for (int i = 0; i < arr.count; i++)
			out << arr[i] << ", ";
		out<<" "<<endl;
		return out;
	};

	friend istream& operator>>(istream& put, container& arr) {
		cout << "Put elements:)" << endl;
		for (int i = 0; i < arr.count; i++)
			put >> arr[i];
		return put;
	};
};

	//-------------------������������, �����������--------------------
	template<typename T, int maxsize>//�������
	container<T, maxsize>::container() {
		count = 0;
		a = new T[maxsize];
	}

	template<typename T, int maxsize>//�������
	container<T, maxsize>::container(const container& arr) {
		if (arr == NULL)
			throw exceptions("The array is empty for copying!");
		count = arr.count;
		a = new T[maxsize];
		for (int i = 0; i < count; i++)
			a[i] = arr.a[i];
	}

	template<typename T, int maxsize>//�������
	container<T, maxsize>::container(T* arr, int c) {
		if (c <= 0)
			throw exceptions("Not correct size!");
		if (arr == NULL)
			throw exceptions("The array is empty!");
		count = c;
		a = new T[maxsize];
		for (int i = 0; i < count; i++)
			a[i] = arr[i];
	}

	template<typename T, int maxsize>//�������
	container<T, maxsize>::~container() {
		count = 0;
		delete[] a;
	}
	//------------����������� ������/������--------------//�������
	template<typename T, int maxsize>
	bool container<T, maxsize>::full() {
		return(count == maxsize);
	}

	template<typename T, int maxsize>
	bool container<T, maxsize>::empty() {
		return(count == 0);
	}
	//-----------------�������� �������-------------------
	template<typename T, int maxsize>//����� ��������� ��������
	int container<T, maxsize>::search(T element) {
		for (int i = 0; i < count; i++)
			if (a[i] == element)
				return i;
		cout << "The element is not found!" << endl;
		return -1;
	}

	template<typename T, int maxsize>//���������� �������� � �����
	void container<T, maxsize>::add(const T element) {
		if (full())
			throw exceptions("The array is full!");
		a[count] = element;
		count++;
	}

	template<typename T, int maxsize>//�������� �������� �� �������
	void container<T, maxsize>::del(T index) {
		if (empty())
			throw exceptions("The array is empty!");
		if ((index < 0) || (index > maxsize)) 
			throw exceptions("There is no such index in the array!");
		int i;
		for (i = index; i < count; i++)
			a[i] = a[i + 1];
		a[i + 1] = 0;
		count--;

		
	}
	//---------------�������� ��������� � []--------------------
	template<typename T, int maxsize>
	T& container<T, maxsize>::operator[](int index) {
		if ((index < 0) || (index >= count))
			throw exceptions("There is no such index in the array!");
		return a[index];
	}

	template<typename T, int maxsize>
	const T& container<T, maxsize>::operator[](int index) const {
		if ((index < 0) || (index >= count))
			throw exceptions("There is no such index in the array!");
		return a[index];
	}
#endif 

