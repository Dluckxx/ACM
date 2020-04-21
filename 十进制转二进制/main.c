#include<stdio.h>

int main(void) {
	int arr[1000] = { 0 }, a[100] = { 0 }, i = 0, j = 0;
	while (1) {
		scanf("%d", &a[j]);
		if (a[j] == 0)
			break;
		while (1) {
			arr[i] = a[j] % 2;
			a[j] /= 2;
			if (a == 0)
				break;
			i++;
		}
		while (i != -1) {
			printf("%d", arr[i]);
			i--;
		}
		j++;
	}
	return 0;
}