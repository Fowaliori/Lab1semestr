#include <stdio.h>
#include <locale.h>
#define mn 5
#define op 100
#define mm 20
#define mc 9


void func1() {
	int A[mn];
	int i;
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	for (i = 0; i < mn; i++) {
		if (A[i] < 0) break;
	}
	if (i == mn) printf("Числа положительные\n");
	else printf("Есть число(а) отрицательное(ые)\n");
}

void func2() {
	int i, a, s, n;
	int A[op];
	for (i = 0, a = 2; a < 530; a++) {
		for (s = 0, n = 2; n < a; n++){
			if (a % n == 0) {
				s = 1;
				break;
			}
		}
		if (s == 0) A[i++] = a;
	}
	A[i] = 0;
	for (i = 0; i < op; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void func3() {
	int j, i, s, m, A[mn], B[mn+1];
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	for (j = 0, i = 0; i < mn; i++) {
		for (m = 2; m < A[i]; m++) {
			if (A[i] % m == 0) break;
		}
		if (m == A[i]) B[j++] = A[i];
	}
	B[j] = 0;
	for (i = 0; i < mn; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
}

void func4() {
	int j, i, s, m, A[mn];
	int n = 5;
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	for (j = 0, i = 0; i < n; i++) {
		for (m = 2; m < A[i]; m++) {
			if (A[i] % m == 0) break;
		}
		if (m == A[i]) {
			for (j = i; j < n - 1; j++) {
				A[j] = A[j + 1];
			}
			n--;
			i--;
		}
	}
	for (i = 0; i < mn; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void func5() {
	int i, a, m, v, A[mc], s, j;

	for (i = 0, a = 2; a < mm && i < mc - 1; a++) {
		for (s = 0, j = 0; j < i; j++) {
			if (a % A[j] == 0) {
				s = 1;
				break;
			}
		}
		if (s == 0) A[i++] = a;
	}
	printf("Простые числа до %d: ", mm);
	for (i = 0; i < mc-1; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void func6() {
	int i, j, c[mn], d, s;
	int n = 5;
	int k = 0;
	s = 0;
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &c[i]);
	}
	int B[mn+10];
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (c[i] == c[j]) {
				printf("%d ", c[i]);
				break;
			}
		}
	}
	for (int d = 0; d < mn; d++) {
		printf("%d ", B[d]);
	}
	printf("\n");
}

void func7() {
	int s, i, A[mc], k, b;
	for (i = 0; i < mc; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	s = 0, b = 0, k = 2;
	for (s = 0, i = 0; i < mc; i++) {
		if (A[i] == A[i + 1]) {
			for (k = 2; i + k < mc && A[i] == A[i + k]; k++);
			if (k > s) {
				s = k;
				b = i;
			}
		}
	}
	if (s == 0 && b == 0) printf("Нет подряд одинаковых чисел\n");
	else printf("Продолжиельность в %d числа. первое число под номером %d", s, b + 1);
	printf("\n");
}

void func8() {
	int j, a, n, s, k,i;
	int A[mm];
	for (j = 0, a = 10; a < 60; a++) {
		for (s = 0, n = a, s = 0; n != 0; n = n / 10) {
			k = n % 10;
			if (k != 0 && a % k != 0) {
				s = 1;
				break;
			}
		}
		if (s == 0) A[j++] = a;
	}
	for (i = 0; i < mm; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void func9() {
	int A[10], i, k;
	for (i = 0; i < 10; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	for (i = 0, k = -1; i < 10; i++) {
		if (A[i] < 0) continue;
		if (k == -1) k = i;
		else
			if (A[i] < A[k]) k = i;
	}
	printf("Минимальное положительное число под номером %d\n", k+1);
}

void func10() {
	int s, i, A[mn];
	for (i = 0; i < mn; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &A[i]);
	}
	for (s = 0, i = 0; i < mn; i++) s = s + A[i];
	printf("Сумама числе в массиве = %d\n", s);
}

int main() {
	setlocale(0, "rus");
	int k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
	k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, k6 = 0, k7 = 0, k8 = 0, k9 = 0, k10 = 0;
	int c = 12;
	int K[10] = {0};
	printf("Выберите функцию 1-10\n");
	printf("1 функция:поиск отрицательных чисел \n");
	printf("2 функция:вывод простых чисел \n");
	printf("3 функция:поиск простых чисел в массиве \n");
	printf("4 функция:сдвиг массива при нахождении простого числа \n");
	printf("5 функция:Простые числа до v \n");
	printf("6 функция:одинаковые значения массива \n");
	printf("7 функция:подряд одникавоые числа \n");
	printf("8 функция:числа делящиеся на последний разряд \n");
	printf("9 функция:минимальное положительное число \n");
	printf("10 функция:сумма чисел в массиве \n");
	while (c != 0) {
		scanf_s("%d", &c);
		if (c == 0) break;
		if (c == 1) {
			func1();
			k1++;
		}
		if (c == 2) {
			func2();
			k2++;
		}
		if (c == 3) {
			func3();
			k3++;
		}
		if (c == 4) {
			func4();
			k4++;
		}
		if (c == 5) {
			func5();
			k5++;
		}
		if (c == 6) {
			func6();
			k6++;
		}
		if (c == 7) {
			func7();
			k7++;
		}
		if (c == 8) {
			func8();
			k8++;
		}
		if (c == 9) {
			func9();
			k9++;
		}
		if (c == 10) {
			func10();
			k10++;
		}
		K[c-1]++;
	}
	printf("Статистика:\n");
	for (int i = 1; i <= 10; i++) {
		printf("Кол-во функций %d: %d\n",i, K[i-1]);
	}
	return 59;
}