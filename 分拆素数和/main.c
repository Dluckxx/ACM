#include<stdio.h>
#define MAX 5000
int check(int n);

int main(void) {
	int i, j, input, count;
	int sushu[MAX] = { 0 };

	for (i = 0, j = 0; j < MAX; i++) {
		if (check(i)) {
			sushu[j] = i;
			j++;
		}
	}
	
	while (scanf("%d", &input) != EOF) {
		if (input == 0)break;
		count = 0;
		for (i = 0; sushu[i] < input; i++) {
			for (j = i + 1; sushu[j] < input; j++) {
				if (sushu[i] + sushu[j] == input)
					count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}

int check(int n)
{
	int i;
	if (n <= 1)
		return 0;
	for (i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}