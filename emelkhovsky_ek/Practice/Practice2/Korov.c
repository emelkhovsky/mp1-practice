﻿#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define N 10
void main() {
	int n, nk, nch, f, r, cop1, cop2, i, kol, k, kor, bik, j, t;
	/*
	ПОЯСНЕНИЕ
	n-кол-во цифр в числах
	nk-число, загаданное компьютером
	nch-число, которое вводит человек
	f,t-флажки
	r-рандомная цифра, помогающая формировать рандомное чило компьютера
	cop1,cop2-просто копии чисел, чтобы не портить nk и nch
	i,k,j-счетчики
	kol-счетчик кол-ва цифр в вводимом числе для проверки
	kor,bik-коровы и быки
	*/
	int a[N] = { 0 };//массив используется сначала для подсчета повторений, а далее в него записываем nch
	int b[N] = { 0 };//в этот массив записываем nk
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf("Введите кол-во цифр в числе\n");
	//начало рандома числа компьютером
	nk = rand() % 9 + 1;
	i = 1;
	while (i<n) {
		r = rand() % 10;
		cop1 = nk;
		f = 0;
		while (cop1>0) {
			if (cop1 % 10 == r) {
				f = 1;
			}
			cop1 = cop1 / 10;
		}
		if (f == 0) {
			nk = nk * 10 + r;
			i++;
		}
	}
	printf("%d\n", nk);
	printf("Число загадано, попробуй угадать\n");

	t = 1;
	while (t == 1) {
		//проверка введеного числа на кол-во цифр
		printf("Введите %d значное число без повторяющихся цифр\n", n);
		scanf("%d", &nch);
		f = 0;
		while (f == 0) {
			kol = 0;
			cop2 = nch;
			while (cop2 > 0) {
				a[cop2 % 10]++;//заполняю массив и смотрю есть ли повторения цифр
				cop2 = cop2 / 10;
				kol++;//проверка на правильное кол-во цифр
			}
			if (kol == n) {
				f = 1;
			}
			for (k = 0; k < n; k++) {//смотрю повторения
				if (a[k] > 1) {
					f = 0;
				}
			}
			if (f == 0) {
				printf("Неправильный ввод, попробуйте еще раз\n");
				scanf("%d", &nch);
				for (k = 0; k < n; k++) {
					a[k] = 0;
				}
			}
		}
		printf("%d\n", nch);

		//коровы и быки
		bik = 0;
		kor = 0;
		cop2 = nk;//делаю копию, чтобы в самом конце использовать 
		for (k = 0; k < n; k++) {//положила в массивы значения человека и компьютера 
			a[k] = nch % 10;
			nch = nch / 10;
			b[k] = cop2 % 10;
			cop2 = cop2 / 10;
		}
		//подсчет быков и коров
		for (k = 0; k < n; k++) {
			for (j = 0; j < n; j++) {
				if ((b[k] == a[j]) && (k == j)) {//считаю быков
					bik++;

				}
				if ((b[k] == a[j]) && (k != j)) {//считаю коров
					kor++;
				}
			}
		}
		printf("%d коров\n", kor);
		printf("%d быков\n", bik);
		if (bik == nk) {
			printf("Вы угадали число, поздравляем!\n");
			f = 0;
		}
		else {
			printf("Попробуйте угадать еще раз\n");
		}
	}
}