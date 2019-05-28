#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h> 
#define N 5

void RAND_SKIDKA(int s[], int n) {//функция рандома скидок
    int i;
    for (i = 0; i<n; i++) {
        s[i] = rand() % 50 + 1;
    }
}


void STRIHKOD(int n, int *k, char shtrih[][4]) {//функция считывания штрихкода и количества товара
    int i, kl, f;
    f = 1;
    char shtrihkod[5];
    while (f == 1) {//f-флажок, показывающий пробили мы все товары из корзины или нет
        printf("Если вы пробили все продукты, введите 0, для продолжения введите штрихкод\n");
        scanf("%s", &(shtrihkod));
        if (b == 0) {
            f = 0;
        }
        else {
            while (strlen(shtrihkod) != 0) {
                printf("Некорректный ввод, попробуйте еще раз\n");
                scanf("%s", &(shtrihkod));
            }
            for (i = 0; i < n; i++) {
                if ((strncmp(shtrihkod, shtrih[i])) == 0) {
                    printf("Введите кол-во\n");
                    scanf("%d", &kl);
                    k[i] += kl;//пополняем массив кол-ва продуктов
                }
            }
            
        }
    }
}

void CHECK(char name[][14], char shtrih[][4], int c[], int k[], int sk[], int n) {//функция вывода позиций чека
    int t = 0, i, j;
    for (i = 0; i < n; i++) {
        if (k[i] != 0) {
            for (j = 0; j < 4; j++)
                printf("штрихкод:%s ", shtrih[i][j]);
            for (j = 0; j < 16; j++)
                printf("%s", name[i][j]);
            printf("цена:%dруб - кол-во:%d - стоимость:%dруб - скидка:%d%%\n",  c[i], k[i], (k[i] * c[i]), sk[i]);
        }
    }
}

int MAIN_CHECK(int c[], int k[], int sk[], int n) {//подсчёт общей скидки и вывод чека
    int i;
    float so = 0, bez = 0, skid;
    for (i = 0; i<n; i++) {
        if (k[i] != 0) {
            bez += k[i] * c[i];//сумма без скидки
            so += k[i] * c[i] * (1 - (0.01 * sk[i]));//сумма со скидкой
        }
    }
    skid = 100 - so / bez * 100;//общая скидка
    printf("Итог:%.0fруб   Скидка:%.0f%%   К оплате:%.0fруб \n", bez, skid, so);
}

void main() {
    char shtrih[N][4] = { "0001","0002","0003","0004","0005" };
    char naim[N][14] = { "Банан","Огурцы солёные","Рыба","Кофе","Вафли" };
    int cena[N] = { 200,70,150,25,37 };
    int kol[N] = { 0 };
    int skidka[N] = { 0 };
    int i;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    RAND_SKIDKA(skidka, N);//заполняем массив скидок на товары
    STRIHKOD(N, kol, shtrih);//считываем штрихкод и кол-во
    for (i = 0; i<N; i++) {
        printf("%d\n", kol[i]);
    }
    CHECK(naim, shtrih, cena, kol, skidka, N);//функция вывода позиций чека
    MAIN_CHECK(cena, kol, skidka, N);//подсчёт общей скидки и вывод чека
    printf("Спасибо за покупку! Приходите еще!\n");
    printf("_$$$$__$$___$__$$$$__$$__$$\n$$__$$_$$___$_$$__$$_$$__$$\n$$$$$$_$$_$_$_$$$$$$_$$$$$$\n$$__$$_$$_$_$_$$__$$_$$__$$\n$$__$$_$$$$$$_$$__$$_$$__$$");

}