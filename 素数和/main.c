#include <stdio.h>

//判断素数函数
int fun(int n)
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

int main()
{
	int sushu[200];
	int a = 0;
	int b;

	for (b = 1;b <= 10000;b++) {
		if (fun(b) == 1) {
			sushu[a] = b;
			a++;
			if (a >= 200) {
				break;
			}
		}
	}

	int temp = 0;

	/*
	while(temp < 200){
	printf("%d\t",sushu[temp]);
	temp++;
	}
	*/

	int n;
	int m;
	scanf_s("%d %d", &n, &m);

	//计算第n到m的素数和函数
	int sum = 0;

	while (n <= m) {
		sum += sushu[n - 1];
		n++;
	}

	printf("%d", sum);
	return 0;
}