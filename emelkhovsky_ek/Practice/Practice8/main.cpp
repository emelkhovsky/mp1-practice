#include<iostream>
#include"matrix.h"
#include<locale.h>
using namespace std;
void main() {
	int con;
	setlocale(LC_ALL, "Rus");
	matrix a, b, mat3;
	cin >> a;
	cin >> b;
	cout << "1�� �������: " << endl;
	cout << a << endl;
	cout << "2�� �������: " << endl;
	cout << b << endl;
	cout << "3�� �������: " << endl;
	cout << mat3 << endl;
	//----------------------------------
	try {
		//a+b
		cout << "a+b: " << endl;
		mat3 = a + b;
		cout << mat3 << endl;
		//a-b
		cout << "a-b: " << endl;
		mat3 = a - b;
		cout << mat3 << endl;
		//a*b
		cout << "a*b: " << endl;
		mat3 = a * b;
		cout << mat3 << endl;
	}
	catch (matrixrazmer) {
		std::cout << "������������ ������ �������!\n";
	}
	//-----------------------------------
	try {
		cout << "������� ���������" << endl;
		cin >> con;
		//a+con
		cout << "a+con: " << endl;
		mat3 = a + con;
		cout << mat3 << endl;
		//a-con
		cout << "a-con: " << endl;
		mat3 = a - con;
		cout << mat3 << endl;
		//a*con
		cout << "a*con: " << endl;
		mat3 = a * con;
		cout << mat3 << endl;
	}
	catch (matrixrazmer) {
		std::cout << "������������ ������ �������!\n";
	}
	//-----------------------------------
	try {
		//a+=b
		cout << "a+=b: " << endl;
		mat3 = a;
		mat3 += b;
		cout << mat3 << endl;
		//a-b
		cout << "a-=b: " << endl;
		mat3 = a;
		mat3 -= b;
		cout << mat3 << endl;
	}
	catch (matrixrazmer) {
		std::cout << "������������ ������ �������!\n";
	}
	//-----------------------------------
	try {
		//a+=con
		cout << "a+con: " << endl;
		mat3 = a;
		mat3 += con;
		cout << mat3 << endl;
		//a-=con
		cout << "a-con: " << endl;
		mat3 = a;
		mat3 -= con;
		cout << mat3 << endl;
		//a*=con
		cout << "a*con: " << endl;
		mat3 = a;
		mat3 *= con;
		cout << mat3 << endl;
	}
	catch (matrixrazmer) {
		std::cout << "������������ ������ �������!\n";
	}
	try {
		cout << a[4] << endl;
		cout << a[-34];
	}
	catch (matrixrazmer) {
		std::cout << "����������� ��������� ������!\n";
	}
}