#include <stdio.h>

//�ж�int a�Ƿ�Ϊһ������
int wan(int a) {
	//�����������飬��ȫ����ֵΪ0
	int yin[500];
	int i;
	for (i = 0;i < 500;i++) {
		yin[i] = 0;
	}
	
	i = 1;

	while (i < a) {
		if (a % i == 0) {
			yin[i - 1] = i;
		}
		i++;
	}

	int sum = 0;

	i = 0;

	while (i < a) {
		sum += yin[i];
		i++;
	}

	if (sum == a) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int input_1 = 0;
	int input_2 = 0;
	int i = 0;
	int accumelate = 0;

	scanf("%d%d", &input_1, &input_2);

	while (input_1 <= input_2) {
		if (wan(input_1) == 1) {
			accumelate++;
		}
		input_1++;
	}

	int temp = 0;
	input_1 -= input_2;

	while (input_1 <= input_2) {
		if (wan(input_1) == 1) {
			temp++;
			printf("%d", input_1);
			if (temp != accumelate) {
				printf(" ");
			}
		}

		input_1++;


	}
	if (accumelate == 0) {
		printf("NIL");
	}
}