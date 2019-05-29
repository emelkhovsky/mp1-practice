#include<iostream>
#include "vector.h"
#include <cmath.h>
#include "Exception.h"
using namespace std;
//-------------------Конструкторы, деструкторы-----------------------
vector::vector(int s) {//конструктор с параметром
    n = s;
    x = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;
}
vector::vector(vector& cop) {//конструктор копирования
    n = cop.n;
    x = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = cop.x[i];
}
vector::~vector() {//деструктор
    delete[] x;
    n = 0;
}
//--------------------Перегрузки операций с векторами----------------------------
const vector& vector::operator=(const vector& t) {//перегрузка =
    if (this == &t)
        return *this;
    delete[] x;
    n = t.n;
    x = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = t.x[i];
    return *this;
}
vector vector::operator+(const vector& t) {//перегрузка +
    if (n!= t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    vector c(n);
    for (int i = 0; i < n; i++) 
        c.x[i] = x[i] + t.x[i];
    return c;
}
vector vector::operator-(const vector& t) {//перегрузка -
    if (n != t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    vector c(n);
    for (int i = 0; i < n; i++)
        c.x[i] = x[i] - t.x[i];
    return c;
}
vector vector::operator*(const vector& t) {//перегрузка скалярное *
    if (n != t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    vector c(n);
    for (int i = 0; i < n; i++)
        c.x[i] = x[i] * t.x[i];
    return c;
}
//--------------------Перегрузки операций с константами----------------------------
vector vector::operator+(double con) {//перегрузка + константа
    vector c(n);
    for (int i = 0; i < n; i++)
        c.x[i] = x[i] + con;
    return c;
}
vector vector::operator-(double con) {//перегрузка - константа
    vector c(n);
    for (int i = 0; i < n; i++)
        c.x[i] = x[i] - con;
    return c;
}
vector vector::operator*(double con) {//перегрузка * константа
    vector c(n);
    for (int i = 0; i < n; i++)
        c.x[i] = x[i] * con;
    return c;
}
//--------------------Перегрузки операций с векторами типа += ----------------------------
vector& vector::operator+=(const vector& t) {//перегрузка +=
    if (n != t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    for (int i = 0; i < n; i++)
        x[i] += t.x[i];
    return *this;
}
vector& vector::operator-=(const vector& t) {//перегрузка -=
    if (n != t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    for (int i = 0; i < n; i++)
        x[i] -= t.x[i];
    return *this;
}
vector& vector::operator*=(const vector& t) {//перегрузка скалярное произведение*=
    if (n != t.n)
        throw exception("Разные размерности!НЕдопустимо!");
    for (int i = 0; i < n; i++)
        x[i] *= t.x[i];
    return *this;
}
//--------------------Перегрузки операций с константами типа += ----------------------------
vector& vector::operator+=(double con) {//перегрузка + константа
    for (int i = 0; i < n; i++)
        x[i] += con;
    return *this;
}
vector& vector::operator-=(double con) {//перегрузка - константа
    for (int i = 0; i < n; i++)
        x[i] -= con;
    return *this;
}
vector& vector::operator*=(double con) {//перегрузка * константа
    for (int i = 0; i < n; i++)
        x[i] *= con;
    return *this;
}
//--------------------- Перегрузка [] ----------------------
double& vector::operator[](int i) {
    if ((i < 0) || (i > n))
        throw exception("НЕдопустимый индекс");
    return x[i-1];
}
const double& vector::operator[](int i) const {
    if ((i < 0) || (i > n))
        throw exception("НЕдопустимый индекс");
    return x[i - 1];
}
//-------------------Различные методы-----------------------
double vector::lenght() {//длинна вектора
    double len = 0;
    for (int i = 0; i < n; i++) 
        len = len + x[i] * x[i];
    len = sqrt(len);
    return len;
}


