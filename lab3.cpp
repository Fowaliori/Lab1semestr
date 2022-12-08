#include <stdio.h>
#include <math.h>
double sum(double x, double eps, int* n) {  // Вычисление значения функции 1/(1+x)^2 через степенной ряд
    double s, sn;                          
    for (s = 0., sn = 1, (*n) = 1; fabs(sn) > eps; (*n)++) { 
        s += sn;
        sn = pow(-1, (*n)) * ((*n) + 1) * pow(x, (*n)); // коэффицент перехода 
    }
    return s;
}
void main() { // вычисление степенного ряда для x в диапазоне от 0.1 до 0.9 с шагом 0.1
    double x, y, c;
    int nn,k;
    for (x = 0.1; x <= 0.9; x += 0.1) {
        c = 1 / (pow(1 + x, 2));
        y = sum(x, 0.0001, &nn);
        printf("n=%d x=%0.1lf\t sum=%0.4lf\t 1/(1+x)^2=%0.4lf\n", nn, x, y, c);
    }
}