#include<stdio.h>

int main()

{

	int a[4][4] = { { 2,3,9,5 },{ 6,7,8,3 },{ 0,5,7,5 },{ 2,1,8,3 } };

	int i, j, k, i0, j0, find = 0;

	printf("数组a:\n");

	for (i = 0;i<4;i++)

	{

		for (j = 0;j<4;j++)

			printf("%3d", a[i][j]);

		printf("\n");

	}

	for (i = 0;i<4;i++)        //穷举所有的行

	{

		j0 = 0;

		for (j = 1;j<4;j++)
			if (a[i][j]>a[i][j0])j0 = j;    //找到第i行上最大的数a[i][j0]

		k = 1;

		for (i0 = 0;i0<4;i0++)    //对找到的该数穷举所有行
			if (a[i0][j0]<a[i][j0])k = 0;    //如它不是本列上最小的数就“一票否决”

		if (k)    //若确认是，就输出，并记录已找到

		{

			printf("鞍点是：a[%d][%d]=%d\n", i, j0, a[i][j0]);

			find = 1;

		}

	}

	if (!find)    //若未找到，则输出提示信息

		printf("此数组无鞍点！\n");

	return 0;
}