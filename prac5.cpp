#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS_



int func5() {
	int i, a, b, c;
	int c1, c2, c3, c4;
	int k;
	for (i = 100; i < 10000; i++) {
		k = 0;
		b = i;
		while (b > 0) {
			b = b / 10;
			k += 1;
		}
		b = i;
		if (k == 3) {
			c1 = b % 10;
			b = b / 10;
			c2 = b % 10;
			b = b / 10;
			c3 = b % 10;
			if ((c3 < c2) && (c2 < c1)) {
				printf("%d \n", i);
			}
		}
		if (k == 4) {
			c1 = b % 10;
			b = b / 10;
			c2 = b % 10;
			b = b / 10;
			c3 = b % 10;
			b = b / 10;
			c4 = b % 10;
			if ((c4 < c3) && (c3 < c2) && (c2 < c1)) {
				printf("%d \n", i);
			}
		}
	}
}

int func8() {
	int i, a, b, c;
	for (i = 5; i < 10000; i++) {
		c = 1;
		b = i / 2;
		for (a = 2; a < i-1; a++) {
			if (i % a == 0) c=c+a;
		}
		//printf("%d %d \n", i,c);
		if (i == c) {
			printf("%d\n", i);
		}
	}
} 

int main() {
	func5();
	func8();
	return 59;
}