#include <stdio.h>

int sum(int a);

int main(void) {
	int year;
	while (scanf("%d", &year) != EOF) {

		if (year == 0)
			break;

		printf("%d\n", year + sum(year - 4));
	}
	return 0;
}

int sum(int a) {
	int i, sum = 0;
	for (i = 1; i <= a; i++) {
		sum += i;
	}
	return sum;
}