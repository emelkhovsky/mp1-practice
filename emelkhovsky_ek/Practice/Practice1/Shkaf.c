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
    h=h*0.01;//�������� � ������� ��
    printf("������� ������ ������ ������(�������,������ ������,������,�����)\n");
    scanf("%f", &w);
    w=w*0.01;
    printf("������� ������� �������(������,�����)\n");
    scanf("%f", &d);
    d=d*0.01;
    printf("������� ��������� ���,��� � ������\n");
    scanf("%f %f %f", &pDVP, &pDSP, &pDER);
    tDVP=0.005;//��������� �������� � �
    tDSP=0.015;
    tDER=0.01;//�� �������� � �
    m = 0;
    v1 = h * w * tDVP;//����� ������ ������
    m = m + v1 * pDVP;
    v2 = h * d * tDSP;//����� 1�� ��������
    m = m + 2 * v2 * pDSP;
    v3 = w * d * tDSP;//����� 1�� �������
    m = m + 2 * v3 * pDSP;
    v4 = h * w * tDER;//��� 1�� ������
    m = m + v4 * pDER;
    v5 = (h - 2 * tDSP) / (0.4 + tDSP) * (w - 2 * tDSP) * (d - tDVP);//����� ���� �����
    m = m + v5 * pDSP;
    printf("����� ����� %f\n", m,"\n");


}
