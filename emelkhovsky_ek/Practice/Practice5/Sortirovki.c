#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 5
//P.S.Данные сортировки предусмотрены для случая сортировки по возрастанию


void FILL_MAS(int a[], int n) {//функция заполнения массива
	int i;
	printf("Ââåäèòå ýëåìåíòû ìàññèâà\n");
	for (i = 0; i<n; i++)
		scanf("%d", &(a[i]));
}


void OUTPUT_MAS(int a[], int n) {//функция вывода массива
	int i;
	for (i = 0; i<n; i++)
		printf("%d ", (a[i]));
}


void SORT_CHOICE(int a[], int n) {
	int i, tmp, j, min, minidx;
	for (i = 0; i<n - 1; i++) {
		min = a[i];
		minidx = i;
		for (j = i + 1; j<n; j++)
			if (a[j]<min) {
				min = a[j];
				minidx = j;
			}
		tmp = a[i];
		a[i] = a[minidx];
		a[minidx] = tmp;
	}
}


void SORT_INSERT(int a[], int n) {
	int i, j, tmp;
	for (i = 1; i<n; i++) {
		j = i - 1;
		tmp = a[i];
		while ((j >= 0) && (a[j]>tmp)) {
			a[j + 1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}


void SORT_BUBBLE(int a[], int n) {
	int i, j, tmp;
	for (i = 0; i<n; i++)
		for (j = 1; j<n - i; j++)
			if (a[j - 1]>a[j]) {
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
}


void SORT_COUNT(int a[], int n) {
	int c, i, j;
	int b[N] = { 0 };
	printf("Введите наименьшее число встречающееся в массиве\n");
	scanf("%d", &c);
	for (i = 0; i<n; i++) {
		b[(a[i] + abs(c))]++;
	}
	for (i = 0; i<n; i++)
		for (j = 0; j<b[i]; j++)
			printf("%d ", (i - abs(c)));
}



void main() {
	int a[N];
	int i, f;
	setlocale(LC_ALL, "Russian");
	FILL_MAS(a, N);
	printf("Введите:\n1-сортировка выбором\n2-сортировка вставками\n3-сортировка пузырьком\n4-сортировка подсчетом\n");
	scanf("%d", &f);
	while ((f != 1) && (f != 2) && (f != 3) && (f != 4)) {
		printf("Некорректный ввод, попробуйте ещё раз\n");
		scanf("%d", &f);
	}

	if (f == 1) {
		SORT_CHOICE(a, N);
		OUTPUT_MAS(a, N);
	}
	else if (f == 2) {
		SORT_INSERT(a, N);
		OUTPUT_MAS(a, N);
	}
	else if (f == 3) {
		SORT_BUBBLE(a, N);
		OUTPUT_MAS(a, N);
	}
	else
		SORT_COUNT(a, N);
}