#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
	float pDVP, pDSP, pDER, h, w, d, tDVP, tDSP, tDER;//�������� ������: ���������, ������, ������, �������, �������
	float v1, v2, v3, v4, v5, m;//���������� ������ � ����� 
	int kol;//kol-���������� �����
	setlocale(LC_ALL, "Rus");
	printf("������� ������ ������ ������(�������,������)\n");
	scanf("%f", &h);
	printf("������� ������ ������ ������(�������,������ ������,������,�����)\n");
	scanf("%f", &w);
	printf("������� ������� �������(������,�����)\n");
	scanf("%f", &d);
	printf("������� ��������� ���,��� � ������\n");
	scanf("%f %f %f", &pDVP, &pDSP, &pDER);
	printf("������� ������� ���,��� � ������\n");
	scanf("%f %f %f", &tDVP, &tDSP, &tDER);
	m = 0;
	v1 = h * w * tDVP;//����� ������ ������
	m = m + v1 * pDVP;
	v2 = h * d * tDSP;//����� 1�� ��������
	m = m + 2 * v2 * pDSP;
	v3 = w * d * tDSP;//����� 1�� �������
	m = m + 2 * v3 * pDSP;
	v4 = h * w * tDER;//��� 1�� ������
	m = m + v4 * pDER;
	kol = floor(h / 41.5);
	printf("���������� ����� %i\n", kol);
	v5 = d * w * tDSP;//����� 1�� �����
	m = m + kol * v5 * pDSP;
	printf("����� ����� %f\n", m,"\n");

}