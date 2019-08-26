#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
    float r1, r2, x1, x2, y1, y2, d;
    setlocale(LC_ALL, "Rus");
    printf("¬ведите координаты центра 1ой окружности и еЄ радиус\n");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("¬ведите координаты центра 2ой окружности и еЄ радиус\n");
    scanf("%f %f %f", &x2, &y2, &r2);
    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {
        printf("ќкружности совпадают\n");
        return;
    }
    if (d > (r1 + r2)) {
        printf("ќкружности лежат поодаль и не имеют общих точек\n");
        return;
    }
    if (d == (r1 + r2)) {
        printf("ќкружности касаютс¤ внешним образом\n");
        return;
    }

    if (d == (fabsf(r1 - r2))) {
        printf("ќкружности касаютс¤ внутренним образом\n");
        return;
    }
    if (d < (fabsf(r1 - r2))) {
        printf("ќкружность лежит внутри окружности \n");
        return;
    }

    if ((d < (r1 + r2)) && (d >(fabsf(r1 - r2)))) {
        printf("ќкружности пересекаютс¤\n");
        return;
    }

}