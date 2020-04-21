#include<stdio.h>

/*需求：给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第列上的最小数。一个矩阵A也可能没有鞍点。
你的任务是找出A的鞍点。*/

int main() {
	//定义数组
	int a[100][100] = { 0 };
	int i = 0;
	int j = 0;
	int i0 = 0;
	int j0 = 0;
	int k = 0;
	int flag = 0;
	//n为矩阵边长
	int n;
	scanf("%d", &n);
	//赋值矩阵
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0;i<n;i++)        //穷举所有的行

	{

		j0 = 0;

		for (j = 1;j<n;j++)
			if (a[i][j]>a[i][j0])j0 = j;    //找到第i行上最大的数a[i][j0]

		k = 1;

		for (i0 = 0;i0<n;i0++)    //对找到的该数穷举所有行
			if (a[i0][j0]<a[i][j0])k = 0;    //如它不是本列上最小的数就“一票否决”

		if (k)    //若确认是，就输出，并记录已找到

		{

			printf("%d %d", i, j0);

			flag = 1;

		}

	}
	/*寻找i行最大值,并赋值给maxhang
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maxhang < juzhen[i][j]) {
				maxhang = juzhen[i][j];
				hang = i;
				lie = j;
			}
		}
		寻找j列最小值,并赋值给minlie
		for (int j = 0; j < n; j++) {
			if (minlie > juzhen[j][lie]) {
				minlie = juzhen[j][lie];
			}
		}
		判断鞍点存在
		if (maxhang == minlie) {
			printf("%d %d", hang, lie);
			flag = 1;
			break;
		}
	}*/
	//如果没有鞍点
	if (flag == 0) {
		printf("NO");
	}

	return 0;
}