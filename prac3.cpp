#include <stdio.h>
#include <locale.h>
#include <math.h>

int func1() {
	int i, r, b, t, c, c1, c2, c3, c4;
	for (i = 100; i <= 9999; i++) {
		r = 0;
		b = i;
		t = i;
		while (b != 0) {
			b = b / 10;
			r++;
		}
		//printf("%d %d \n", i, r);
		if (r == 3) {
			c1 = t % 10;
			t = t / 10;
			c2 = t % 10;
			t = t / 10;
			c3 = t;
			c = c1 + c2 + c3;
			if (pow(c, 3) == i) printf("%d %d \n", c,i);
			//printf("%d %d %d \n", c3, c2, c1);
		}
		if (r == 4) {
			c1 = t % 10;
			t = t / 10;
			c2 = t % 10;
			t = t / 10;
			c3 = t % 10;
			t = t / 10;
			c4 = t % 10;
			c = c1 + c2 + c3 + c4;
			if (pow(c, 3) == i) printf("%d %d \n", c,i);
			//printf("%d %d %d %d \n", c4, c3, c2, c1);
		}
		
	}
}
int func2() {
	
}
int main() {
	func1();
	printf("\n");

	return 59;
}