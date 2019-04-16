#include<iostream>
#include "vector.h"
#include "cmath"
#include "Exception.h"
using namespace std;
//-------------------������������, �����������-----------------------
vector::vector(){//����������� �� ���������
	n = 0;
	x = nullptr;
}
vector::vector(int s) {//����������� � ����������
	n = s;
	x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = 0;
}
vector::vector(vector& cop) {//����������� �����������
	n = cop.n;
	x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = cop.x[i];
}
vector::~vector() {//����������
	delete[] x;
	n = 0;
}
//--------------------���������� �������� � ���������----------------------------
vector& vector::operator=(const vector& t) {//���������� =
	if (this == &t)
		return *this;
	delete[] x;
	n = t.n;
	x = new double[n];
	for (int i = 0; i < n; i++)
		x[i] = t.x[i];
	return *this;
}
vector vector::operator+(const vector& t) {//���������� +
	if (n!= t.n)
		throw Exception("������ �����������!�����������!");
	vector c(n);
	for (int i = 0; i < n; i++) 
		c.x[i] = x[i] + t.x[i];
	return c;
}
vector vector::operator-(const vector& t) {//���������� -
	if (n != t.n)
		throw Exception("������ �����������!�����������!");
	vector c(n);
	for (int i = 0; i < n; i++)
		c.x[i] = x[i] - t.x[i];
	return c;
}
vector vector::operator*(const vector& t) {//���������� ��������� *
	if (n != t.n)
		throw Exception("������ �����������!�����������!");
	vector c(n);
	for (int i = 0; i < n; i++)
		c.x[i] = x[i] * t.x[i];
	return c;
}
//--------------------���������� �������� � �����������----------------------------
vector vector::operator+(double con) {//���������� + ���������
	vector c(n);
	for (int i = 0; i < n; i++)
		c.x[i] = x[i] + con;
	return c;
}
vector vector::operator-(double con) {//���������� - ���������
	vector c(n);
	for (int i = 0; i < n; i++)
		c.x[i] = x[i] - con;
	return c;
}
vector vector::operator*(double con) {//���������� * ���������
	vector c(n);
	for (int i = 0; i < n; i++)
		c.x[i] = x[i] * con;
	return c;
}
//--------------------���������� �������� � ��������� ���� += ----------------------------
vector vector::operator+=(const vector& t) {//���������� +=
	if (n != t.n)
		throw Exception("������ �����������!�����������!");
	for (int i = 0; i < n; i++)
		x[i] += t.x[i];
	return *this;
}
vector vector::operator-=(const vector& t) {//���������� -=
	if (n != t.n)
		throw Exception("������ �����������!�����������!");
	for (int i = 0; i < n; i++)
		x[i] -= t.x[i];
	return *this;
}
vector vector::operator*=(const vector& t) {//���������� ��������� ������������*=
	if (n != t.n)
		throw Exception("������ �����������!�����������!");
	for (int i = 0; i < n; i++)
		x[i] *= t.x[i];
	return *this;
}
//--------------------���������� �������� � ����������� ���� += ----------------------------
vector vector::operator+=(double con) {//���������� + ���������
	for (int i = 0; i < n; i++)
		x[i] += con;
	return *this;
}
vector vector::operator-=(double con) {//���������� - ���������
	for (int i = 0; i < n; i++)
		x[i] -= con;
	return *this;
}
vector vector::operator*=(double con) {//���������� * ���������
	for (int i = 0; i < n; i++)
		x[i] *= con;
	return *this;
}
//--------------------- ���������� [] ----------------------
double& vector::operator[](int i) {
	return x[i-1];
}
//-------------------��������� ������-----------------------
double vector::lenght() {//������ �������
	double len = 0;
	for (int i = 0; i < n; i++) 
		len = len + pow(x[i], 2);
	len = sqrt(len);
	return len;
}
void vector::Output() {//����� ��������� �������
	cout << "("<<x[0];
	for (int i = 1; i < n; i++) 
		cout << ", " << x[i] ;
	cout << ")" << endl;
}
void vector::Input() {//���� ����������� � ��������� �������
	x = new double[n];
	cout << "������� ���������� �������" << endl;
	for (int i = 0; i < n; i++)
		cin>>x[i];
}

