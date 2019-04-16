#include <iostream>
#include "vector.h"
#include "locale.h"
#include "Exception.h"
using namespace std;
void main() {
	try {
		int n, i;
		double con, len;
		setlocale(LC_ALL, "Rus");
		cout << "������� ����������� ��������" << endl;
		cin >> n;
		vector a(n), b(n), c(n);
		a.Input();
		b.Input();
		cout << "���������� ������� a: ";
		a.Output();
		cout << "���������� ������� b: ";
		b.Output();
		cout << "���������� ������� c: ";
		c.Output();
		//----------------------------------
		//a+b
		cout << "a+b: " << endl;
		c = a + b;
		c.Output();
		//a-b
		cout << "a-b: " << endl;
		c = a - b;
		c.Output();
		//��������� ������������ a*b
		cout << "a*b: " << endl;
		c = a * b;
		c.Output();
		//-----------------------------------
		cout << "������� ���������" << endl;
		cin >> con;
		//a+con
		cout << "a+con: " << endl;
		c = a + con;
		c.Output();
		//a-con
		cout << "a-con: " << endl;
		c = a - con;
		c.Output();
		//a*con
		cout << "a*con: " << endl;
		c = a * con;
		c.Output();
		//-----------------------------------
		//a+=b
		cout << "a+=b: " << endl;
		c = a;
		c += b;
		c.Output();
		//a-b
		cout << "a-=b: " << endl;
		c = a;
		c -= b;
		c.Output();
		//��������� ������������ a*=b
		cout << "a*=b: " << endl;
		c = a;
		c *= b;
		c.Output();
		//-----------------------------------
		//a+=con
		cout << "a+con: " << endl;
		c = a;
		c += con;
		c.Output();
		//a-=con
		cout << "a-con: " << endl;
		c = a;
		c -= con;
		c.Output();
		//a*=con
		cout << "a*con: " << endl;
		c = a;
		c *= con;
		c.Output();
		//------------------------------------------
		len = a.lenght();
		cout << "������ ������� a: " << len << endl;
		len = b.lenght();
		cout << "������ ������� b: " << len << endl;
		//------------------------------------------
		cout << "����� ���������� � ������� a �� ������ �������?" << endl;
		cin >> i;
		cout << a[i] << endl;
	}
	catch (Exception ex)
	{
		ex.Print();
	}
}
