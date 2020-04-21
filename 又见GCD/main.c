#include<stdio.h>

struct Test {
	int a;
	int b;
	int c;
};

typedef struct Test TEST;

int check(int a, int b);

int main(void) {

	int n, count;

	scanf("%d", &n);

	TEST t;

	while (n--) {
		
		scanf("%d %d", &t.a, &t.b);

		for (count = 2; ; count++) {

			t.c = t.b * count;
		
			if (t.b == check(t.a, t.c)) {
				printf("%d\n", t.c);
				break;
			}

		}
	}

	return 0;
}

int check(int a, int b)
{
	int i;

	if (a > b)
		i = b;
	else
		i = a;

	while (i) {
		if (a%i == 0 && b%i == 0) {
			return i;
			break;
		}
		i--;
	}

	return 0;
}
