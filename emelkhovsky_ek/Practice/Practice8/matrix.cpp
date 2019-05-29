#include<iostream>
#include "Exception.h"
#include"matrix.h"
#include<locale.h>
using namespace std;
//--------------������������, �����������------------------
matrix::matrix() {
	columns = 2;
	rows = 3;
	mat = new int[columns*rows];
	for (int i = 0; i < columns*rows; i++)
		mat[i] = 0;
};
matrix::matrix(int c, int r) {
	if ((c <= 0) || (r <= 0))
		throw exception("����������� ������ ��������!");
	columns = c;
	rows = r;
	mat = new int[columns*rows];
	for (int i = 0; i < columns*rows; i++)
		mat[i] = 0;
};
matrix::matrix(matrix& m) {
	columns = m.columns;
	rows = m.rows;
	mat = new int[columns*rows];
	for (int i = 0; i < columns*rows; i++)
		mat[i]=m.mat[i];
};
matrix::~matrix() {
	columns = 0;
	rows = 0;
	delete[] mat;
};
//-------------���������� ��������-------------------
const matrix& matrix::operator=(const matrix& m) {
	if (this == &m)
		return *this;
	columns = m.columns;
	rows = m.rows;
	delete[] mat;
	mat = new int[columns*rows];
	for (int i = 0; i < columns*rows; i++)
		mat[i] = m.mat[i];
	return *this;
}
//--------------������� �������� � ���������-------------------
matrix matrix::operator+(const matrix& m) {
	if ((rows != m.rows) || (columns != m.columns))
		throw exception("������������ ������ �������!");
	matrix result(m.columns, m.rows);
	for (int i = 0; i < columns*rows; i++)
		result.mat[i] = m.mat[i]+mat[i];
	return result;
};
matrix matrix::operator-(const matrix& m) {
	if ((rows != m.rows) || (columns != m.columns))
		throw exception("������������ ������ �������!");
	matrix result(m.columns, m.rows);
	for (int i = 0; i < columns*rows; i++)
		result.mat[i] =  mat[i]-m.mat[i];
	return result;
};
matrix matrix::operator*(const matrix& m) {
	if (columns != m.rows)
		throw exception("������������ ������ �������!");
	matrix result(m.columns, rows);
	int c=0, r=0;
	for (int i = 0; i < rows; i++) 
		for(int j = 0; j < m.columns; j++)
			for (int f = 0; f < columns; f++) 
				result.mat[i * m.columns + j] += mat[i * columns + f] * m.mat[f * m.columns + j];
	return result;
};
//----------������� �������� � �����������------------

matrix matrix::operator+(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] = con  + mat[i];
	return *this;
};
matrix matrix::operator-(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] =  mat[i]-con;
	return *this;
};
matrix matrix::operator*(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] = mat[i] * con;
	return *this;
};
//----------�������� ���� += � ���������------------
matrix matrix::operator+=(const matrix& m) {
	if ((rows != m.rows) || (columns != m.columns))
		throw exception("������������ ������ �������!");
	for (int i = 0; i < columns*rows; i++)
		mat[i] += m.mat[i];
	return *this;
}
matrix matrix::operator-=(const matrix& m) {
	if ((rows != m.rows) || (columns != m.columns))
		throw exception("������������ ������ �������!");
	for (int i = 0; i < columns*rows; i++)
		mat[i] -= m.mat[i];
	return *this;
}
//----------�������� ���� += � �����������------------
matrix matrix::operator+=(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] += con;
	return *this;
}
matrix matrix::operator-=(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] -= con;
	return *this;
}
matrix matrix::operator*=(int con) {
	for (int i = 0; i < columns*rows; i++)
		mat[i] *= con;
	return *this;
}
//--------------��������� ������� � ����������----------------
void matrix::output() {
	cout << "(";
	int t = 0;
	for (int i = 0; i < columns*rows; i++) {
		cout << mat[i];
		t++;
		if (t == columns) {
			cout << ")" << endl;
			cout << "(";
			t = 0;
		}
		else 
			cout << " ";
	}
};
int* matrix::operator[](int index) {
	if ((index < 0) || (index >= rows))
		throw exception("����������� ��������� ������!");
	return(mat + columns * index);
}
void matrix::input() {
	cout << "������� ���-�� �������� � ����� ������� " << endl;
	cin>>columns;
	cin>>rows;
	if ((columns <= 0) || (rows <= 0))
		throw exception("����������� ������ ��������!");
	cout << "������� �������� �������(���������)" << endl;
	mat = new int[columns*rows];
	for (int i = 0; i < columns*rows; i++)
		cin >> mat[i];
}