#include <stdio.h>

int fun(int n)
{
	int i;
	if (n <= 1)
	{
		return 0;
	}
	for (i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main() {

	int input = 0;

	scanf("%d", &input);

	if (fun(input) == 1) {
		printf("%d=%d", input, input);
	}
	else {
		printf("%d=", input);
		int a = 2;
		int b = 0;
		int temp;
		while (a < 1000000) {
			temp = input;
			if (input % a == 0) {
				if (fun(a) == 1) {
					printf("%d", a);
					input /= a;
					if (input != 1) {
						printf("x");
					}
					else {
						break;
					}
				}
			}
			if (input == temp) {
			a++;
			}
		}
	}

	return 0;
}