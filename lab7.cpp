#include <stdio.h>
#include <locale.h>
#define n 5

int func1(int s[]) {
	for (int i = 1; i < n; i++) {
		for (int k = i; k != 0 && s[k] < s[k - 1]; k--) {
			int c = s[k]; s[k] = s[k - 1]; s[k - 1] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	return s;
}

int func2(int s[], int a[], int* v) {
	int k = 1;
	int kmax, poss, pose;
	kmax = 0;
	(*v) = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] > s[i - 1]){
			k++;
			if (k >= kmax) {
				kmax = k;
				poss = i + 1 - kmax;
				pose = i;
			}
		}
		else if (s[i] <= s[i - 1]) {
			k = 1;
		}
	}
	(*v) = 0;
	for (int i = poss; i <= pose; i++, (*v)++) {
		a[(*v)] = s[i];
		s[i] = -1;
		}
	//printf("%d %d\n", poss, pose);
}

int main() {
	setlocale(0, "rus");
	int s[n];
	int a[n];
	int vv;
	for (int i = 0; i < n; i++) {
		printf("Введите %d число массива\n", i + 1);
		scanf_s("%d", &s[i]);
	}
	printf("Входной массив до изменений\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
	func2(s,a,&vv);
	//func1(s);
	printf("\n");
	int cnt = sizeof(a) / sizeof(int);
	printf("Выходной массив: ");
	for (int i = 0; i < vv; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Входной массив после изменений: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
}