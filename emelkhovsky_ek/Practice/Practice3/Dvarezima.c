#include "stdio.h"
#include "locale.h"
#include "time.h"
void mode_1() {
	int random, user, kol;
	random = rand() % 1000 + 1 ;
	kol = 0;
	printf("��������� ������� ����� �� 1 �� 1000!\n�������� �������!\n");
	//	printf("%d\n",random);
	scanf("%d", &user);
	while (user != random) {
		while ((user<1) || (user>1000)) {
			printf("���������� ���� �� 1 �� 1000\n");
			scanf("%d", &user);
		}
		kol++;
		if (user>random) {
			printf("�� ����� ����� ������, ��� ����������\n");
		}
		else if (user<random) {
			printf("�� ����� ����� ������ ��� ����������\n");
		}
		scanf("%d", &user);
	}
	printf("�� ������� ����� � %d ������� \n", kol);
}


void mode_2() {
	int user, random, a, b, kol;
	kol = 0;
	b = 1001;
	a = 1;
	char o;
	printf("������� ����� ������� ����� ���������� ���������\n");
	scanf("%d", &user);

	while ((user<1) || (user>1000)) {
		printf("���������� ���� �� 1 �� 1000\n");
		scanf("%d", &user);
	}

	random = rand() % (b - a) + a;
	printf("��������� ������� ����� %d, ������� ���� ����� ������, ������ ��� �����?\n", random);

	while (random != user) {
		kol++;
		scanf("%s", &o);

		if (o == '>') {
			a = random + 1;
		}
		else if (o == '<') {
			b = random;
		}

		else break;
		random = rand() % (b - a) + a;
		printf("��������� ������� ����� %d, ������� ���� ����� ������, ������ ��� �����?\n", random);
	}
	printf("��������� ������ � %d ������� \n", kol);
}
void main() {

	int mode;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("������� �����:\n1 ����� ����������� �����\n2 ����� ���������� �����\n");
	scanf("%d", &mode);
	if (mode == 1) {
		mode_1();
	}
	else if (mode == 2) {
		mode_2();
	}
	else {
		printf("����� 2 ������");
	}

}
