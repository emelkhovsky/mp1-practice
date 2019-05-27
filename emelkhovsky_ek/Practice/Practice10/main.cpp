#include "iostream"
#include "container.h"
#include "locale.h"
#include "exceptions.h"
#include "conio.h"
using namespace std;
int main() {
		int index, element;
		int mas1[5] = { 1,2,3,4,5 };
		float mas2[3] = { 0.1f,0.2f,0.3f };
		float mas22[3] = { 0.1f,0.2f,0.3f };
		int mas3[2] = { 0 };
		int mas4[1] = {};
		setlocale(LC_ALL, "rus");
		container<int, 10> array1(mas1, 5);
		container<float, 5> array2(mas2, 3);
		container<int, 1> array3(mas3, 1);

		try {
			container<int, 2> array4(mas4, -3);//���������� ��-�� ������������� ������� � ������� ���������� 4
		}
		catch (exceptions exc) {
			exc.print();
		}
	
		cout << "1�� ���������:" << endl;
		cout << array1;
		cout << "2�� ���������:" << endl;
		cout << array2;
		cout << "3�� ���������:" << endl;
		cout << array3;

		//------------------------------------����������--------------------------------------
		cout << "������� �������, ������� ������ �������� � 1�� ������" << endl;//��� ����������
		cin >> element;
		array1.add(element);
		cout << array1 << endl;

		try {
			cout << "������� �������, ������� ������ �������� � 3�� ������" << endl;//���������� ��-�� ������� ���������� 3
			cin >> element;
			array3.add(element);
		}
		catch (exceptions exc) {
			exc.print();
		}
		//------------------------------��������-----------------------------
		try {
			cout << "��������:" << endl;
			array2.del(0);
			cout << array2 << endl;
			array2.del(1);
			cout << array2 << endl;
			array2.del(2);
			array2.del(0);//���������� ��-�� ������� ����������
		}
		catch (exceptions exc) {
			exc.print();
		}
		cout << "������� ������� �� 2 ������� -1�� �������:"<< endl;
		try {
			array2.del(-1);//���������� ��-�� ��������������� ��������
		}
		catch (exceptions exc) {
			exc.print();
		}
		//----------------------------�����---------------------------
		cout << "������� �������, ������� �� ������ ����� � ������� 1" << endl;
		cin >> element;
		element = array1.search(element);
		cout << "��� " << element << "-�� �������" << endl;

		cout << "������� ����� � 1�� ��������� 1000:" << endl;
		try {
			array1.search(1000);//���������� ��-�� ��������������� ��������
		}
		catch (exceptions exc) {
			exc.print();
		}
		//-------------------------����� ��������------------------------
		cout << "������� ������ ��������, ������ �� ������ ������� �� ������� 1" << endl;
		cin >> index;
		cout << "�������:"<<array1[index] << endl;

		cout << "������� ����� � 1�� ��������� -35 �������:" << endl;
		try {
			cout << array1[1000] << endl;//���������� ��-�� ��������������� �������
		}
		catch (exceptions exc) {
			exc.print();
		}
//-------------------2222222222222222222222222222222222222222222222222222222222------------------------------------------
		int *mass1[5];
		int i;
		for ( i = 0; i < 5; i++)
			mass1[i] = &mas1[i];
		container<int*, 10> arrayy1(mass1, 5);
		container<int*, 10> arrayy2(arrayy1);

		try {
		cout << "1�� ���������:" << endl;
		cout << arrayy1;
		cout << "2�� ���������:" << endl;
		cout << arrayy2;
		int a = 6;
		int* a1 = &a;
		arrayy1.add(a1);
		cout << "1�� ���������:" << endl;
		cout << arrayy1;
		}
		catch (exceptions exc) {
			exc.print();
		}

		try {
			cout << "��������" << endl;
			arrayy1.del(&arrayy1[0]);
			cout << arrayy1 << endl;;
		}
		catch (exceptions exc) {
			exc.print();
		}

		try {
			cout << &arrayy1[2] << endl;;
		}
		catch (exceptions exc) {
			exc.print();
		}
		_getch();
}