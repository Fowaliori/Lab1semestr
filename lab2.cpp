#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(0, "rus");
	int o, d, i, n, m, g,odin,mnogo,k;
	printf("Числовой ребус: ОДИН+ОДИН=МНОГО\n");
	for (o = 0; o < 10; o++) {
		for (d = 0; d < 10; d++) {
			for (i = 0; i < 10; i++) {
				for (n = 0; n < 10; n++) {
					for (m = 0; m < 10; m++) {
						for (g = 0; g < 10; g++) {
							k = 0;
							odin = o * 1000 + d * 100 + i * 10 + n;
							mnogo = m * 10000 + n * 1000 + o * 100 + g * 10 + o;
							if (odin / 1000 != 0 && mnogo / 10000 != 0) {
								if (odin + odin == mnogo) printf("%d + %d = %d\n", odin, odin, mnogo);
							}
						}
					}
				}
			}
		}
	}
	printf("_________________\n");
	printf("\n");
	printf("Три различные цифры\n");
	int a, b, c, r, l,j;
	for (a = 1; a < 10; a++) {
		for (b = 0; b < 10; b++) {
			for (c = 0; c < 10; c++) {
				if (a != b && a != c && b != c) {
					r = a * 100 + b * 10 + c;
					d = a + b + c;
					l = d * d;
					j = r / l;
					if (r % l == 0) printf("a = %d, b = %d, c = %d, сумма чисел = %d, квадрат суммы = %d, %d / %d = %d \n", a, b, c, d, l, r, l, j);
				}
			}
		}
	}
}