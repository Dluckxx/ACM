#include<stdio.h>

int main(void) {

	int temp[102] = { 0 };
	int a, n, x, m, i = 0, j = 0, k = 0, l = 1;

	while (1) {
		a = 102;
		i = 0;
		j = 0;
		while (a--)
			temp[a] = 0;

		scanf("%d %d", &n, &x);

		if (n == 0 && x == 0)break;

		while (i < n)
			scanf("%d", &temp[i++]);
		
		temp[i] = x;


		for (k = 0;k < n + 1; k++) {
			for (l = 1;l < n + 1;l++) {
				if (temp[l - 1] > temp[l]) {
					m = temp[l - 1];
					temp[l - 1] = temp[l];
					temp[l] = m;
				}
			}
		}

		while (j < n + 1) {
			printf("%d",temp[j++]);
			if (j != n + 1)
				printf(" ");
			else
				printf("\n");
		}
	}

	return 0;
}