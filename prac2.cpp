#include <stdio.h>
#include <locale.h>
#define mn 5

int func1() {
	int i, j, s;
	int A[mn];
	i = 0; s = 0;
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	i = 0; s = 0;
	while (i < mn) {
		if (i % 2 == 0) s = s + A[i];
		else s = s - A[i];
		i++;
	}
	printf("%d", s);
}

int func2() {
	int i, k, A[5];
	for (i = 0; i < 5; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	i = 1; k = 0;
	while (i < 5) {
		if (A[i] > A[k]) k = i;
		i++;
	}
	printf("%d",k);

}

int main() {
	setlocale(0, "rus");
	func1(); // Сумма значений массива под чётными индексами и разность значений массива под нечётныыми индексами
	printf("\n");
	func2(); // индекс максимального числа
	return 59;
}