#include <stdio.h>
#include<math.h>

void speak(int a)
{
	switch (a)
	{
	case 0:
		printf("ling");
		break;
	case 1:
		printf("yi");
		break;
	case 2:
		printf("er");
		break;
	case 3:
		printf("san");
		break;
	case 4:
		printf("si");
		break;
	case 5:
		printf("wu");
		break;
	case 6:
		printf("liu");
		break;
	case 7:
		printf("qi");
		break;
	case 8:
		printf("ba");
		break;
	case 9:
		printf("jiu");
		break;
	default:
		printf("ÎÞÐ§×Ö·û");
		break;
	}
}


int main() {
	int input;

	scanf("%d", &input);

	if (input < 0) {
		input = abs(input);
		printf("fu ");
	}

	int arr[6];
	int ge = input % 10;
	int shi = input % 100 / 10;
	int bai = input % 1000 / 100;
	int qian = input % 10000 / 1000;
	int wan = input % 100000 / 10000;
	int shiwan = input % 1000000 / 100000;

	arr[0] = shiwan;
	arr[1] = wan;
	arr[2] = qian;
	arr[3] = bai;
	arr[4] = shi;
	arr[5] = ge;

	int count = 0;
	int i = 0;

	while (i < 6) {
		if (arr[i] == 0) {
			count++;
		}
		else if (arr[i] != 0) {
			break;
		}
		i++;
	}

	while (count < 6) {
		speak(arr[count]);
		if (count == 5)break;
		printf(" ");
		count++;
	}

	if (input == 0) {
		speak(0);
	}
	return 0;
}
