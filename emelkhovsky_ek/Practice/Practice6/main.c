#include "stdio.h"
#include "vector.h"
#include "locale.h"

void main() {
	vector a, b, c;
	int f, flag = 1;
	double an, len;
	float s;
	setlocale(LC_ALL, "Rus");
	while (flag) {
		printf("������ �������:\n0.������� �������\n1. ����� ��������\n2. a-b\n3. b-a\n4. ���� ����� ���������\n5. ��������� ������������\n6. ����� ������� �������\n7. ������ ������� �������\n8. ������� �������\n9. ���������\n");
		scanf("%d", &f);
		switch (f) {
		case 0:
			a = create();
			b = create();
			break;
		case 1:
			c = sum(a, b);
			printf("����� ������� a � b:\n");
			output(c);
			del(c);
			break;
		case 2:
			c = dif(a, b);
			printf("�������� a � b:\n");
			output(c);
			del(c);
			break;
		case 3:
			c = dif(b, a);
			printf("�������� b � a:\n");
			output(c);
			del(c);
			break;
		case 4:
			printf("���� ����� ��������� a � b: ");
			an = angle(a, b);
			printf("%.2f\n", an);
			break;
		case 5:
			s = scalar(a, b);
			printf("��������� ������������: %.2f\n", s);
			break;
		case 6:
			len = length(a);
			printf("������ ������� a: %lf\n", len);
			break;
		case 7:
			len = length(b);
			printf("������ ������� b: %lf\n", len);
			break;
		case 8:
			del(a);
			del(b);
			printf("������� ������� �������\n");
			break;
		case 9:
			flag = 0;
			break;
		}
	}
}