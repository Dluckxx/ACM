#include<stdio.h>

/*���󣺸���һ��n*n����A������A�İ�����һ��λ�ã�i��j�����ڸ�λ���ϵ�Ԫ���ǵ�i���ϵ�������������ϵ���С����һ������AҲ����û�а��㡣
����������ҳ�A�İ��㡣*/

int main() {
	//��������
	int a[100][100] = { 0 };
	int i = 0;
	int j = 0;
	int i0 = 0;
	int j0 = 0;
	int k = 0;
	int flag = 0;
	//nΪ����߳�
	int n;
	scanf("%d", &n);
	//��ֵ����
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0;i<n;i++)        //������е���

	{

		j0 = 0;

		for (j = 1;j<n;j++)
			if (a[i][j]>a[i][j0])j0 = j;    //�ҵ���i����������a[i][j0]

		k = 1;

		for (i0 = 0;i0<n;i0++)    //���ҵ��ĸ������������
			if (a[i0][j0]<a[i][j0])k = 0;    //�������Ǳ�������С�����͡�һƱ�����

		if (k)    //��ȷ���ǣ������������¼���ҵ�

		{

			printf("%d %d", i, j0);

			flag = 1;

		}

	}
	/*Ѱ��i�����ֵ,����ֵ��maxhang
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maxhang < juzhen[i][j]) {
				maxhang = juzhen[i][j];
				hang = i;
				lie = j;
			}
		}
		Ѱ��j����Сֵ,����ֵ��minlie
		for (int j = 0; j < n; j++) {
			if (minlie > juzhen[j][lie]) {
				minlie = juzhen[j][lie];
			}
		}
		�жϰ������
		if (maxhang == minlie) {
			printf("%d %d", hang, lie);
			flag = 1;
			break;
		}
	}*/
	//���û�а���
	if (flag == 0) {
		printf("NO");
	}

	return 0;
}