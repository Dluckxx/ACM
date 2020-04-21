#include<stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int i = 0;
	scanf("%d/%d", &a, &b);
	printf("0.");

	while (i < 200) {
		a *= 10;
		int temp = a / b;
		printf("%d", temp);
		if (a%b == 0) {
			break;
		}
		a %= b;
		i++;
	}
	return 0;
}