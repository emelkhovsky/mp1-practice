#include"iostream"
#include"matrix.h"
#include"locale.h"
#include "Exception.h"
using namespace std;
void main() {
	try {
	int con;
	setlocale(LC_ALL, "Rus");
	matrix a, b, mat3;
	a.input();
	b.input();
	cout << "1�� �������: " << endl;
	a.output();
	cout << "2�� �������: " << endl;
	b.output();
	cout << "3�� �������: " << endl;
	mat3.output();
	//----------------------------------
	//a+b
	cout << "a+b: " << endl;
	mat3 = a + b;
	mat3.output();
	//a-b
	cout << "a-b: " << endl;
	mat3 = a - b;
	mat3.output();
	//a*b
	cout << "a*b: " << endl;
	mat3 = a * b;
	mat3.output();
	//-----------------------------------
	cout << "������� ���������" << endl;
	cin >> con;
	//a+con
	cout << "a+con: " << endl;
	mat3 = a + con;
	mat3.output();
	//a-con
	cout << "a-con: " << endl;
	mat3 = a - con;
	mat3.output();
	//a*con
	cout << "a*con: " << endl;
	mat3 = a * con;
	mat3.output();
	//-----------------------------------
	//a+=b
	cout << "a+=b: " << endl;
	mat3 = a;
	mat3 += b;
	mat3.output();
	//a-b
	cout << "a-=b: " << endl;
	mat3 = a;
	mat3 -= b;
	mat3.output();
	//-----------------------------------
	//a+=con
	cout << "a+con: " << endl;
	mat3 = a;
	mat3 += con;
	mat3.output();
	//a-=con
	cout << "a-con: " << endl;
	mat3 = a;
	mat3 -= con;
	mat3.output();
	//a*=con
	cout << "a*con: " << endl;
	mat3 = a;
	mat3 *= con;
	mat3.output();
}
catch (Exception ex)
{
	ex.Print();
}
}