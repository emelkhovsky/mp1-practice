#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
	float r1, r2, x1, x2, y1, y2, d;
	setlocale(LC_ALL, "Rus");
	printf("������� ���������� ������ 1�� ���������� � � ������\n");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("������� ���������� ������ 2�� ���������� � � ������\n");
	scanf("%f %f %f", &x2, &y2, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {
		printf("���������� ���������\n");
		return;
	}
	if (d > (r1 + r2)) {
		printf("���������� ����� ������� � �� ����� ����� �����\n");
		return;
	}
	if (d == (r1 + r2)) {
		printf("���������� �������� ������� �������\n");
		return;
	}

	if (d == (fabsf(r1 - r2))) {
		printf("���������� �������� ���������� �������\n");
		return;
	}
	if (d < (fabsf(r1 - r2))) {
		printf("���������� ����� ������ ���������� \n");
		return;
	}

	if ((d < (r1 + r2)) && (d >(fabsf(r1 - r2)))) {
		printf("���������� ������������\n");
		return;
	}

}