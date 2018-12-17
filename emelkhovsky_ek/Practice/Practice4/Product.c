#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#define N 5

void RAND_SKIDKA(int s[], int n) {//������� ������� ������
	int i;
	for (i = 0; i<n; i++) {
		s[i] = rand() % 50 + 1;
	}
}


void STRIHKOD(int s[], int n, int *k) {//������� ���������� ��������� � ���������� ������
	int i, b, kl, f;
	f = 1;
	while (f == 1) {//f-������, ������������ ������� �� ��� ������ �� ������� ��� ���
		printf("���� �� ������� ��� ��������, ������� 0, ��� ����������� ������� ��������\n");
		scanf("%d", &b);
		if (b == 0) {
			f = 0;
		}
		else {
			while (b>5) {
				printf("������������ ����, ���������� ��� ���\n");
				scanf("%d", &b);
			}
			i = b - 1;
			printf("������� ���-��\n");
			scanf("%d", &kl);
			k[i] += kl;
		}
	}
}

void CHECK(char **p, int s[], int c[], int k[], int sk[], int n) {//������� ������ ������� ����
	int t = 0, i;
	for (i = 0; i<n; i++) {
		if (k[i] != 0) {
			printf("��������:000%d - %s - ����:%d��� - ���-��:%d - ���������:%d��� - ������:%d%%\n", s[i], *(p + i), c[i], k[i], (k[i] * c[i]), sk[i]);
		}
	}
}

int MAIN_CHECK(int c[], int k[], int sk[], int n) {//������� ����� ������ � ����� ����
	int i;
	float so = 0, bez = 0, skid;
	for (i = 0; i<n; i++) {
		if (k[i] != 0) {
			bez += k[i] * c[i];//����� ��� ������
			so += k[i] * c[i] * (1 - (0.01 * sk[i]));//����� �� �������
		}
	}
	skid = 100 - so / bez * 100;//����� ������
	printf("����:%.0f���   ������:%.0f%%   � ������:%.0f��� \n", bez, skid, so);
}

void main() {
	int shtrih[N] = { 1,2,3,4,5 };
	char *naim[N] = { "�����","������ ������","����","����","�����" };
	int cena[N] = { 200,70,150,25,37 };
	int kol[N] = { 0 };
	int skidka[N] = { 0 };
	int i;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	RAND_SKIDKA(skidka, N);//��������� ������ ������ �� ������
	STRIHKOD(shtrih, N, kol);//��������� �������� � ���-��
	for (i = 0; i<N; i++) {
		printf("%d\n", kol[i]);
	}
	CHECK(naim, shtrih, cena, kol, skidka, N);//������� ������ ������� ����
	MAIN_CHECK(cena, kol, skidka, N);//������� ����� ������ � ����� ����
	printf("������� �� �������! ��������� ���!\n");
	printf("_$$$$__$$___$__$$$$__$$__$$\n$$__$$_$$___$_$$__$$_$$__$$\n$$$$$$_$$_$_$_$$$$$$_$$$$$$\n$$__$$_$$_$_$_$$__$$_$$__$$\n$$__$$_$$$$$$_$$__$$_$$__$$");

}