#include<stdio.h>
#define MAX 1000

int ctoi(char a);
int max(char *a, char *b);

int main(void)
{
	int n, i, j, temp;
	char num1[MAX], num2[MAX];
	int result[MAX] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		if (i)printf("\n");
		scanf("%s %s", num1, num2);

		for (j = max(num1, num2); j > 0; j--)
		{
			temp = ctoi(num1[j - 1]) + ctoi(num2[j - 1]);
			result[j] += temp % 10;
			result[j - 1] += temp / 10;
		}

		printf("Case %d\n%s + %s = ", i+1, num1, num2);

		if (result[0])printf("%d", result[0]);
		for (j = 1; j <= strlen(num1); j++)
		{
			printf("%d", result[j]);
		}

		printf("\n");
	}

	return 0;
}

int ctoi(char a) {
	int ans;
	ans = a - 48;
	return ans;
}

int max(char *a, char *b) {
	if (strlen(a) > stelen(b))
		return a;
	else
		return b;
}