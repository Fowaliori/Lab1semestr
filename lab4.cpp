#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
	setlocale(0, "rus");
	int n = 1;
	int poss,pose,d;
	int nmax = 0;
	char u;
	char st[] = "aaaabcddddddddddddedfffffhhhgreyyygfrjjj";
	int k = 1;
	int o;
	printf("%s - изначальная строка\n", st);
	while(k!=0){
		k++;
		for (int i = 0; st[i] != '\0'; i++) {
			if (st[i] == st[i + 1]) {
				n++;
				if (n > nmax) {
					u = st[i];
					nmax = n;
				}
			}
			else if (st[i] != st[i + 1]) {
				poss = i + 1 - nmax;
				if (nmax > 1) {
					for (o = poss; st[o + nmax] != '\0'; o++) {
						st[o] = st[o + nmax];
					}
					st[o] = '\0';
					printf("%s %d,%d%c\n", st,poss, nmax, u);
				}
				i = i - nmax;
				n = 1;
				nmax = 0;
			}
		}
		if (k > 30) k = 0;
	}
	printf("%s - остаток строки", st);
}
